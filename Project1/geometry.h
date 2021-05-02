#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <GL/glew.h>

#include "loaders/texture/texture.h"

enum class TextureType {
	DDS,
	BMP
};

struct Texture {
	GLuint texture_id;
};

class Geometry
{
protected:
	Texture texture = Texture();

	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> vertices;

public:
	Geometry(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals);
	Geometry();

	Texture get_texture();
	void set_texture(Texture texture);

	void load_texture(std::string url, TextureType texture_type);

	void setup(GLuint program_id, GLuint& vao, GLuint& vbo_vertices, GLuint& vbo_uvs, GLuint& vbo_normals, GLuint& position_id, GLuint& normal_id, GLuint& uv_id);

	std::vector<glm::vec3> get_normals();
	std::vector<glm::vec2> get_uvs();
	std::vector<glm::vec3> get_vertices();

};

