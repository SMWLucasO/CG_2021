#include "bird_move_animation.h"

void BirdMoveAnimation::decide_direction()
{
	int direction = rand() % 3;

	// decide a direction to move in based upon a random number 'direction' [0, 2]
	if (direction == 0)
	{
		this->movement_incrementor = glm::vec3(1, 0, 0);
		this->owner->set_rotations(glm::vec3(0, 0, 0));
	}
	else if (direction == 1)
	{
		this->movement_incrementor = glm::vec3(1, 0, 1);
		this->owner->set_rotations(glm::vec3(0, -45, 0));
	}
	else if (direction == 2)
	{
		this->movement_incrementor = glm::vec3(0, 0, 1);
		this->owner->set_rotations(glm::vec3(0, -90, 0));
	}
}

void BirdMoveAnimation::execute()
{
	// change direction every ~10 seconds (1 second = 60 execution calls.)
	if (this->execution_calls % 600 == 0)
		decide_direction();

	this->execution_calls += 1;

	glm::vec3 position = this->owner->get_position();

	// Keep the birds within our given bounds.
	if (position.x >= x_end)
		position.x = x_start;

	if (position.z >= z_end)
		position.z = z_start;

	if (position.x < x_start)
		position.x = x_end;

	if (position.z < z_start)
		position.z = z_end;

	// move the object.
	position += this->movement_incrementor;
	
	// update the position for the object
	this->owner->set_position(position);
}


