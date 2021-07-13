#pragma once

#include "transformation.h"
#include "animation.h"

class Entity
{
private:
	// the transformations of the entity.
	Transformations transformations = Transformations();

	// the entity's animation.
	Animation* animation = nullptr;

	// boolean determining whether the animation may be executed (if there is one)
	bool allow_animation_execution = false;
public:
	virtual void setup() = 0;
	virtual void render() = 0;

	/**
	* Get the transformations of this entity.
	*
	* @return Transformations&
	*/
	Transformations& get_transformations();

	/**
	* Set the transformations for this entity.
	*
	* @param transformations the transformations to be applied.
	*/
	void set_transformations(Transformations transformations);

	/**
	* Get the entity's position.
	*
	* @return glm::vec3
	*/
	glm::vec3 get_position();
	
	/**
	* Set the entity's position.
	*
	* @param position the position to which the entity should be moved.
	*/
	void set_position(glm::vec3 position);
	
	/**
	* Get the x/y/z rotations of the entity
	*
	* @return glm::vec3
	*/
	glm::vec3 get_rotations();
	
	/**
	* Set the x/y/z rotations of the entity.
	*
	* @param rotations the x/y/z rotations of the entity.
	*/
	void set_rotations(glm::vec3 rotations);

	/**
	* Get the scaling of the entity in x/y/z form.
	*
	* @return glm::vec3
	*/
	glm::vec3 get_scaling();

	/**
	* Set the scale of the entity.
	*
	* @param scaling the x/y/z scaling of the entity.
	*/
	void set_scaling(glm::vec3 scaling);

	/**
	* Set the animation to be executed. Note that the previous animation will be destroyed.
	* 
	* @param animation a heap-allocated pointer to the animation object.
	*/
	void set_animation(Animation* animation);

	/**
	* Get the animation of the given entity.
	* 
	* @return Animation
	*/
	Animation& get_animation();

	/**
	* Activate the animation so that it starts playing.
	*/
	void activate_animation();

};

