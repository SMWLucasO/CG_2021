#pragma once

#include "animation.h"

class BirdMoveAnimation: public Animation
{
private:
	glm::vec3 direction;
public:
	void execute();
};

