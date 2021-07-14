#include "toggle_door_animation.h"

void ToggleDoorAnimation::execute()
{
	if (!this->is_active()) return;

	glm::vec3 rotations = this->owner->get_rotations();

	if (!door_is_opened)
	{
		if (rotations.y >= 90) {
			this->door_is_opened = true;
			this->set_active(false);
		}	
		else
			rotations.y += 2.25;
	}
	else 
	{
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