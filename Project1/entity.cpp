#include "entity.h"


Transformations& Entity::get_transformations()
{
    return this->transformations;
}

void Entity::set_transformations(Transformations transformations)
{
    this->transformations = transformations;
}

glm::vec3 Entity::get_rotations()
{
	return this->transformations.rotations;
}

void Entity::set_rotations(glm::vec3 rotations)
{
	this->transformations.rotations = rotations;
}

glm::vec3 Entity::get_scaling()
{
	return this->transformations.scaling;
}

void Entity::set_scaling(glm::vec3 scaling)
{
	this->transformations.scaling = scaling;
}

void Entity::set_animation(Animation* animation)
{
	delete this->animation;
	this->animation = animation;
}

Animation& Entity::get_animation()
{
	return *this->animation;
}

glm::vec3 Entity::get_position()
{
	return this->transformations.position;
}

void Entity::set_position(glm::vec3 position)
{
	this->transformations.position = position;
}
