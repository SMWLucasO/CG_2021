#include "couch_wave_animation.h"

void CouchWaveAnimation::execute()
{
	// 5 ticks per addition of a seat in moving has shown to look the best to create
	// the wave effect.
	this->execution_calls += 1;
	if (this->execution_calls >= 5)
	{
		this->execution_calls = 0;
		this->couch_seats_to_animate += 1;
	}

	// loop through the seats we can currently access.
	for (int i = 0; i < this->couch_seats_to_animate; i++)
	{
		if (i >= this->couch_seats.size())
			break;

		CouchWaveAnimationData& data = this->couch_seats[i];
		
		glm::vec3 position = data.animation_entity->get_position();

		// if the seat is allowed to move, we just keep moving it up
		// until it reaches the limit, it has the range: [initial, initial + 0.3]
		if (data.may_go_up)
		{
			if (position.y < data.initial_transformations.position.y + 0.3)
				position.y += 0.03;
			else
			{
				// once we've reached the top, the animation should go back down.
				// thus we aren't allowed to go up anymore & we have to go back down.
				data.may_go_up = false;
				data.move_position_back = true;
			}
				
		}
		else if (data.move_position_back)
		{
			// we keep moving down until we get back to the original position.
			if (position.y > data.initial_transformations.position.y)
				position.y -= 0.03;
		}

		// update the position ofc.
		data.animation_entity->set_position(position);
	}

	size_t final_seat_index = this->couch_seats.size() - 1;
	CouchWaveAnimationData& final_seat = this->couch_seats[final_seat_index];

	// if the final seat may go up, or it is not back at the initial position
	// then the animation is not completed, thus we wait.
	if (final_seat.may_go_up ||
		final_seat.animation_entity->get_position().y > final_seat.initial_transformations.position.y) return;
	
	// once we're back at our initial transformation (after the entire animation) 
	// we reset the previously changed values.

	this->couch_seats_to_animate = 0;

	for (int i = 0; i < this->couch_seats.size(); ++i)
	{
		CouchWaveAnimationData& data = this->couch_seats[i];
		data.may_go_up = true;
		data.move_position_back = false;
	}
}

void CouchWaveAnimation::register_couch_seat(Mesh* couch_seat)
{
	CouchWaveAnimationData data;

	data.initial_transformations = Animation::extract_transformation_data(couch_seat);
	data.animation_entity = couch_seat;

	this->couch_seats.push_back(data);
}
