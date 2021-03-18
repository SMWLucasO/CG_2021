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

glm::vec3 Lighting::get_ambient_color()
{
	return this->ambient_color;
}

void Lighting::set_ambient_color(glm::vec3 ambient_color)
{
	this->ambient_color = ambient_color;
}

glm::vec3 Lighting::get_diffuse_color()
{
	return this->diffuse_color;
}

void Lighting::set_diffuse_color(glm::vec3 diffuse_color)
{
	this->diffuse_color = diffuse_color;
}

void Lighting::set_position(glm::vec3 position)
{
	this->position = position;
}
