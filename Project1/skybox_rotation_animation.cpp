#include "skybox_rotation_animation.h"

void SkyboxRotationAnimation::execute()
{
	glm::vec3 rotations = this->owner->get_rotations();
	rotations.y += 0.1;

	// Make sure we keep in the range [0, 359], 
	// 360* = 0*, so we can cut it back to 0 once it reaches 360.
	if (rotations.y >= 360)
		rotations.y = 0;

	// update rotations.
	this->owner->set_rotations(rotations);
}
