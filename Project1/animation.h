#pragma once

#include "transformation.h"
#include "entity.h"
#include "mesh.h"

struct AnimationData 
{
	Mesh* animation_entity;
	Transformations initial_transformations;
};

class Animation
{
private:
	// boolean determining whether the animation is active.
	bool active = false;
protected:
	// The transformations which the animation applies.
	Transformations transformations;

	// The entity that owns the animation.
	Entity* owner;
public:
	Animation();

	/**
	* Handle the animation.
	* 
	* This method is called 60 times per seconds (60fps).
	*/
	virtual void execute() = 0;

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

	/**
	* Set the owner of this animation.
	* 
	* @param the entity to be set as owner of this animation.
	*/
	void set_owner(Entity* owner);

	/**
	* Extract transformation data from the given mesh.
	* 
	* @param mesh the mesh to extract the transformation data from.
	* 
	* @return Transformations
	*/
	static Transformations extract_transformation_data(Mesh* mesh);
};

