#pragma once

#include "animation.h"

class ToggleDoorAnimation: public Animation
{
private:
public:
	void enter();
	void process();
	void exit();
};
