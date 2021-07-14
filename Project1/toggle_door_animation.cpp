#include "toggle_door_animation.h"

void ToggleDoorAnimation::execute()
{
	glm::vec3 rotations = this->owner->get_rotations();

	// When the door isn't open, we're opening it.
	if (!door_is_opened)
	{
		// once we have a 90* rotation, the door is officially open. 
		// otherwise, add 2.25 to the y-axis rotation
		if (rotations.y >= 90) {
			this->door_is_opened = true;
			this->set_active(false);
		}	
		else
			rotations.y += 2.25;
	}
	else 
	{
		// once we have a 0* rotation, the door is officially closed.
		// otherwise, remove 2.25 from the y-axis rotation.
		if (rotations.y <= 0)
		{
			this->door_is_opened = false;
			this->set_active(false);
		}
		else
			rotations.y -= 2.25;
	}

	this->owner->set_rotations(rotations);
}