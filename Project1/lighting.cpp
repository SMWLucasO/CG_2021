#include "lighting.h"

Lighting* Lighting::instance{ nullptr };

Lighting::Lighting()
{
}

Lighting::~Lighting()
{
	delete this->instance;
}

Lighting* Lighting::get_instance()
{
	if (instance == nullptr)
		instance = new Lighting();

	return instance;
}

glm::vec3 Lighting::get_position()
{
	return this->position;
}

void Lighting::set_position(glm::vec3 position)
{
	this->position = position;
}
