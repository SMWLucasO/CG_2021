#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <GL/glew.h>

struct Material {
	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 1.0);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;
};

struct Texture {

};

class Geometry
{
private:
	Material material;
	Texture texture;

	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> vertices;

public:
	Material get_material();
	void set_material(Material material);

	Texture get_texture();
	void set_texture(Texture texture);

	std::vector<glm::vec3> get_normals();
	std::vector<glm::vec2> get_uvs();
	std::vector<glm::vec3> get_vertices();

};

