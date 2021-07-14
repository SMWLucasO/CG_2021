#include "move_right_bird_wing_animation.h"

void MoveRightBirdWingAnimation::execute()
{
	glm::vec3 rotations = this->owner->get_rotations();

	// rotate the right wing up & down in the range [-10, 25]
	// with a speed of 4* in the z-axis

	// check if we've reached the bounds.
	if (rotations.z >= 25)
		this->rotate_back_down = true;
	else if (rotations.z <= -10)
		this->rotate_back_down = false;

	// update the rotation
	if (this->rotate_back_down)
		rotations.z -= 4;
	else
		rotations.z += 4;

	// set new rotations.
	this->owner->set_rotations(rotations);
}
