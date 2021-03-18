#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <GL/glew.h>

struct Material {
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;
};

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
	Material material = Material();
	Texture texture = Texture();
	Uniforms uniforms = Uniforms();

	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> vertices;

	bool inited = false;

public:
	Geometry(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals);
	Geometry();

	Material get_material();
	void set_material(Material material);

	Texture get_texture();
	void set_texture(Texture texture);

	Uniforms get_uniforms();
	void set_uniforms(Uniforms uniforms);

	void set_inited(bool inited);
	bool is_inited();

	std::vector<glm::vec3> get_normals();
	std::vector<glm::vec2> get_uvs();
	std::vector<glm::vec3> get_vertices();

};

