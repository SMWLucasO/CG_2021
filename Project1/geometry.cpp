#include "geometry.h"


Geometry::Geometry(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals)
{
	this->vertices = vertices;
	this->normals = normals;
	this->uvs = uvs;
}

Geometry::Geometry()
{
	// in this  case, do nothing.
}

Texture Geometry::get_texture()
{
	return this->texture;
}

void Geometry::set_texture(Texture texture)
{
	this->texture = texture;
}

Uniforms Geometry::get_uniforms()
{
	return this->uniforms;
}

void Geometry::set_uniforms(Uniforms uniforms)
{
	this->uniforms = uniforms;
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
