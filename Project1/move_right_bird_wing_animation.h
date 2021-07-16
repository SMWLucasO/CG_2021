#pragma once

#include "animation.h"

class MoveRightBirdWingAnimation: public Animation
{
private:
	bool rotate_back_down = false;
public:
	void execute();
};
