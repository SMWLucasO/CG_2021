#pragma once

#include "transformation.h"

class Animation
{
private:
	// The next part of the animation in this list.
	Animation* next;

	// boolean determining whether the animation is active.
	bool active = false;
protected:
	// The transformations which the animation applies.
	Transformations transformations;
public:
	Animation();
	/**
	* Animation destructor.
	*/
	~Animation();

	/**
	* Handle any memory allocation or other setup stuff.
	* 
	* Called upon first execution of this event.
	*/
	virtual void enter() = 0;

	/**
	* Handle the animation.
	* 
	* This method is called 60 times per seconds (60fps).
	*/
	virtual void process() = 0;

	/**
	* Handle any memory deallocation or other cleanup stuff.
	* 
	* Called when exiting this event so that the next one may be started.
	*/
	virtual void exit() = 0;

	/**
	* activate or deactivate the animation.
	* 
	* @param active the bool determining whether the animation is active or not.
	*/
	void set_active(bool active);

	/**
	* Boolean determining whether the animation is active.
	* 
	* @return bool
	*/
	bool is_active();


};

