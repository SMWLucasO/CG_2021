#include "animation.h"

Animation::~Animation()
{
	// this will keep calling the destructor of the next animation until everything is destroyed!
	if (this->next != nullptr)
		delete this->next;
}
