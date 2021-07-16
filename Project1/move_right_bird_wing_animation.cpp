#include "move_right_bird_wing_animation.h"

void MoveRightBirdWingAnimation::execute()
{
	// due to the way the right wing is placed
	// moving it negatively moves it up
	// and moving it positively moves it down

	// rotate the left wing up & down in the range [-25, 10]
	// with a speed of 4* in the z-axis

	glm::vec3 rotations = this->owner->get_rotations();

	// check if we've reached the bounds.
	if (rotations.x <= -25)
		this->rotate_back_down = true;
	else if (rotations.x >= 10)
		this->rotate_back_down = false;

	// update the rotation
	if (this->rotate_back_down)
		rotations.x += 4;
	else
		rotations.x -= 4;

	// set the new rotations.
	this->owner->set_rotations(rotations);
}
