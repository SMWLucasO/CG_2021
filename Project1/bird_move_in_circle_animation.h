#pragma once

#include "animation.h"

class BirdMoveInCircleAnimation: public Animation
{
private:
public:
	void enter();

	void process();

	void exit();
};

