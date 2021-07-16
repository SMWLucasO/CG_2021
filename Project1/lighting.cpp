#include "lighting.h"

// the single Lighting instance.
Lighting* Lighting::instance{ nullptr };

Lighting::Lighting()
{
}

/**
* Lighting destructor.
*/
Lighting::~Lighting()
{
	// free memory by deleting the static instance.
	delete this->instance;
}

/**
* Get the single instance of the world lighting. 
* 
* @return Lighting*
*/
Lighting* Lighting::get_instance()
{
	if (instance == nullptr) // create a new instance of lighting if none exists yet.
		instance = new Lighting();

	return instance;
}

/**
* Get the position of the Lightning.
* 
* @return glm::vec3
*/
glm::vec3 Lighting::get_position()
{
	return this->position;
}

/**
* Set the position for the Lighting.
*/
void Lighting::set_position(glm::vec3 position)
{
	this->position = position;
}
