#include "move_left_bird_wing_animation.h"

void MoveLeftBirdWingAnimation::execute()
{
	// due to the way the left wing is placed
	// moving it negatively moves it up
	// and moving it positively moves it down

	// rotate the left wing up & down in the range [-25, 10]
	// with a speed of 4* in the z-axis

	glm::vec3 rotations = this->owner->get_rotations();

	// check if we've reached the bounds.
	if (rotations.z <= -25)
		this->rotate_back_down = true;
	else if (rotations.z >= 10)
		this->rotate_back_down = false;

	// update the rotation
	if (this->rotate_back_down)
		rotations.z += 4;
	else
		rotations.z -= 4;

	// set the new rotations.
	this->owner->set_rotations(rotations);
}
