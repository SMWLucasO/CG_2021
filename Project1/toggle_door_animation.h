#pragma once

#include "animation.h"

class ToggleDoorAnimation: public Animation
{
private:
	// determines whether we should open or close the door.
	// true => close door.
	// false => open door.
	bool door_is_opened = false;
public:
	void execute();
};

