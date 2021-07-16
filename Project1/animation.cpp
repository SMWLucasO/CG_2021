#include "animation.h"

Animation::Animation()
{
}

void Animation::set_active(bool active)
{
	this->active = active;
}

bool Animation::is_active()
{
	return this->active;
}

void Animation::set_owner(Entity* owner)
{
	this->owner = owner;
}

Transformations Animation::extract_transformation_data(Mesh* mesh)
{
	Transformations transformations;
	transformations.rotations = mesh->get_transformations().rotations;
	transformations.position = mesh->get_transformations().position;
	transformations.scaling = mesh->get_transformations().scaling;

	return transformations;
}
