#pragma once

#include "animation.h"

class MoveLeftBirdWingAnimation: public Animation
{
private:
	bool rotate_back_down = false;
public:
	void execute();
};

