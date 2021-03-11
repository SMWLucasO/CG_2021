#include "Geometry.h"

Geometry::Geometry(Material material, glm::vec3 position)
{
	this->material = material;
	this->transformations = Transformations();
	this->position = position;

	std::cout << "Created a geometry!" << std::endl;
}

Geometry::Geometry(Material material): Geometry(material, glm::vec3(0.0, 0.0, 0.0))
{
}

Geometry::Geometry(): Geometry(BasicMaterial()) 
{
}

Transformations Geometry::get_transformations()
{
	return this->transformations;
}

void Geometry::set_transformations(Transformations transformations)
{
	this->transformations = transformations;
}

Material Geometry::get_material()
{
	return this->material;
}

void Geometry::set_material(Material material)
{
	this->material = material;
}

glm::vec3 Geometry::get_position()
{
	return this->position;
}

void Geometry::set_position(glm::vec3 position)
{
	this->position = position;
}
