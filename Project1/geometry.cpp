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

void Geometry::load_texture(std::string url, TextureType texture_type)
{
	switch (texture_type) {
		case TextureType::BMP:
			this->texture.texture_id = loadBMP(url.c_str());
			break;
		case TextureType::DDS:
			this->texture.texture_id = loadDDS(url.c_str());
			break;
	}
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
