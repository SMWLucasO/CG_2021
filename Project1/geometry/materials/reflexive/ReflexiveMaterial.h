#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "../Material.h"
#include "../../../world/light/Light.h"

class ReflexiveMaterial: public Material
{
private:
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

	GLuint uniform_material_ambient;
	GLuint uniform_light_pos;
	GLuint uniform_material_diffuse;

	Light* light;

public:
	ReflexiveMaterial();
	ReflexiveMaterial(Light& light);
	virtual void setup_uniforms(GLuint program_id);
	virtual void send_uniforms(GLuint program_id);
	virtual void fill_uniforms(GLuint program_id);
};

