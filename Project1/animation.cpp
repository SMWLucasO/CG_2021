#include "animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
	// this will keep calling the destructor of the next animation until everything is destroyed!
	if (this->next != nullptr)
		delete this->next;
}

void Animation::set_active(bool active)
{
	this->active = active;
}

bool Animation::is_active()
{
	return this->active;
}
