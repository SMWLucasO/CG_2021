#include "move_left_bird_wing_animation.h"

void MoveLeftBirdWingAnimation::execute()
{
	glm::vec3 rotations = this->owner->get_rotations();

	// rotate the left wing up & down in the range [-10, 25]
	// with a speed of 4* in the z-axis

	// check if we've reached the bounds.
	if (rotations.x >= 25)
		this->rotate_back_down = true;
	else if (rotations.x <= -10)
		this->rotate_back_down = false;

	// update the rotation
	if (this->rotate_back_down)
		rotations.x -= 4;
	else
		rotations.x += 4;

	// set new rotations.
	this->owner->set_rotations(rotations);
}
