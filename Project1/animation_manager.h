#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "animation.h"

class AnimationManager
{
private:
	std::unordered_map<char, Animation*> keyed_animations;

	// The animations that are run once per tick.
	// Important: we define a 'tick' as a 60th of a second.
	std::vector<Animation*> ticked_animations;

	// The single animation manager instance.
	static AnimationManager* instance;

	AnimationManager();

	/**
	* AnimationManager destructor.
	*/
	~AnimationManager();
public:
	AnimationManager(AnimationManager& geometry_manager) = delete;
	AnimationManager(const AnimationManager& geometry_manager) = delete;

	void operator =(const AnimationManager&) = delete;

	/**
	* Access the AnimationManager singleton.
	*
	* @return AnimationManager*
	*/
	static AnimationManager* get_instance();

	/**
	* Register the animation to the animation manager so that it may be executed 60 times per second.
	*
	* @param animation the animation to be registered.
	*/
	void register_entity_animation(Animation* animation);

	/**
	* Register the animation to the animation manager so that it may be executed on key press.
	* 
	* @param key the key to listen for to execute the animation
	* @param animation the animation to be executed when the key is pressed.
	*/
	void register_onkeypress_entity_animation(char key, Animation* animation);

	/**
	* Execute all ticked animations and enabled keyed animations that are currently active.
	*/
	void execute_ticked_animations();

	/**
	* Enable or disable the execution of the keyed animation.
	* 
	* @param key the key which is bound to the animation to start executing.
	*/
	void toggle_executing_keyed_animation(char key);

};

