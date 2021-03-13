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

void Geometry::render(Camera &camera, float screen_width, float screen_height)
{
	// 'load' shader


	// setup matrices
	glm::mat4 model;
	glm::scale(model, this->transformations.scaling);

	// rotations
	glm::rotate(model, glm::radians(this->transformations.rotation_x), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::rotate(model, glm::radians(this->transformations.rotation_y), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::rotate(model, glm::radians(this->transformations.rotation_z), glm::vec3(0.0f, 0.0f, 1.0f));
	
	glm::translate(model, this->transformations.translation);

	glm::mat4 view = glm::lookAt(
		camera.get_position(),  // eye
		glm::vec3(0.0, 0.0, 0.0),  // center
		glm::vec3(0.0, 1.0, 0.0));  // up
	glm::mat4 projection = glm::perspective(
		glm::radians(camera.get_fov()),
		1.0f * screen_width / screen_height, 0.1f,
		20.0f);

	// setup buffers

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
