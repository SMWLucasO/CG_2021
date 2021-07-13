#include "animation_manager.h"

// The single animation manager instance.
AnimationManager* AnimationManager::instance{ nullptr };

AnimationManager::AnimationManager()
{
}

AnimationManager::~AnimationManager()
{
	delete this->instance;
}

AnimationManager* AnimationManager::get_instance()
{
	if (AnimationManager::instance == nullptr) // create an animation manager instance if none exists yet.
		AnimationManager::instance = new AnimationManager();

	return AnimationManager::instance;
}

void AnimationManager::register_entity_animation(Animation* animation)
{
	animation->set_active(true);
	this->ticked_animations.push_back(animation);
}

void AnimationManager::register_onkeypress_entity_animation(char key, Animation* animation)
{
	this->keyed_animations.emplace(key, animation);
}

void AnimationManager::execute_ticked_animations()
{
	// execute all animations on that are registered on the ticked animations list.
	std::for_each(this->ticked_animations.begin(), this->ticked_animations.end(),
		[](Animation* anim) { anim->execute(); }
	);
}

void AnimationManager::toggle_executing_keyed_animation(char key)
{
	// In this case, there is no animation registered for the specified key.
	if (this->keyed_animations.find(key) == this->keyed_animations.end())
		return;

	Animation* animation = this->keyed_animations[key];

	// toggle the keyed animation.
	if (animation->is_active())
	{
		// remove animation from the tick animations.
		this->ticked_animations.erase(std::remove(this->ticked_animations.begin(), this->ticked_animations.end(), animation),
			this->ticked_animations.end());

		// set animation inactive
		animation->set_active(false);
	}
	else
	{
		this->ticked_animations.push_back(animation);
		animation->set_active(true);
	}
}
