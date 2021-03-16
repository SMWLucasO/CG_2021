#include "geometry.h"


Material Geometry::get_material()
{
	return this->material;
}

void Geometry::set_material(Material material)
{
	this->material = material;
}

Texture Geometry::get_texture()
{
	return this->texture;
}

void Geometry::set_texture(Texture texture)
{
	this->texture = texture;
}

std::vector<glm::vec3> Geometry::get_normals()
{
	return this->vertices;
}

std::vector<glm::vec2> Geometry::get_uvs()
{
	return this->uvs;
}

std::vector<glm::vec3> Geometry::get_vertices()
{
	return this->vertices;
}
