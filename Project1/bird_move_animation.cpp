#include "bird_move_animation.h"

#include <iostream>

void BirdMoveAnimation::execute()
{
	glm::vec3 rotations = this->owner->get_rotations();
	glm::vec3 position = this->owner->get_position();

	rotations.y += 5;
	if (rotations.y >= 360)
		rotations.y = 0;

	glm::vec3 dir;
	dir.x = cos(glm::radians(rotations.y)) * cos(glm::radians(rotations.x));
	dir.y = sin(glm::radians(rotations.x));
	dir.z = sin(glm::radians(rotations.y)) * cos(glm::radians(rotations.x));
	this->direction = glm::normalize(dir);

	position += glm::vec3(0.1, 0, 0.1) * this->direction;

	this->owner->set_rotations(rotations);
	this->owner->set_position(position);
}

