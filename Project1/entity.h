#pragma once

#include "transformation.h"

class Entity
{
private:
	Transformations transformations = Transformations();
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


};

