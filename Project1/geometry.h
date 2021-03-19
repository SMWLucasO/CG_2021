#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <GL/glew.h>

struct Texture {
	GLuint texture_id;
};


// Maybe these uniforms belong to the shader? Doubtful, but possible.
struct Uniforms {
	GLuint uniform_mv;
	GLuint uniform_p;
	GLuint uniform_proj;
	GLuint uniform_light_pos;
	GLuint uniform_specular;
	GLuint uniform_material_power;
	GLuint uniform_material_ambient;
	GLuint uniform_material_diffuse;
};


class Geometry
{
private:
	Texture texture = Texture();
	Uniforms uniforms = Uniforms();

	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> vertices;

	bool inited = false;

public:
	Geometry(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals);
	Geometry();

	Texture get_texture();
	void set_texture(Texture texture);

	Uniforms get_uniforms();
	void set_uniforms(Uniforms uniforms);

	std::vector<glm::vec3> get_normals();
	std::vector<glm::vec2> get_uvs();
	std::vector<glm::vec3> get_vertices();

};

