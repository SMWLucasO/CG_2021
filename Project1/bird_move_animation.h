#pragma once

#include "animation.h"

class BirdMoveAnimation: public Animation
{
private:
	int x_start = -10, x_end = 37;
	int z_start = -13, z_end = 79;
	glm::vec3 incrementor;
	
	int execution_calls = 0;

	void decide_direction();
public:
	void execute();
	
};