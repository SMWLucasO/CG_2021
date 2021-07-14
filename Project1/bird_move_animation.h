#pragma once

#include "animation.h"

class BirdMoveAnimation: public Animation
{
private:
	// The bounds in which the bird moves.
	int x_start = -10, x_end = 37;
	int z_start = -13, z_end = 79;

	// an incrementor for the direction to move towards.
	glm::vec3 movement_incrementor;
	
	// a counter, 60 execution_calls = 1 second.
	int execution_calls = 0;

	/**
	* Randomly decide which direction the animation should move towards.
	*/
	void decide_direction();
public:
	void execute();
	
};