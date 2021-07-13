#pragma once

#include "animation.h"

class SkyboxRotationAnimation: public Animation
{
public:
	void enter();
	void process();
	void exit();
};

