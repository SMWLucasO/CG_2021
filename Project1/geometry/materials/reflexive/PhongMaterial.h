#pragma once

#include "../../../shading/shading.h"
#include "ReflexiveMaterial.h"

#include <glm/glm.hpp>

class PhongMaterial: public ReflexiveMaterial {
private:
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;

	GLuint uniform_specular;
	GLuint uniform_material_power;

public:
	PhongMaterial();
	PhongMaterial(Light& light);
	virtual void setup_uniforms(GLuint program_id);
	virtual void send_uniforms(GLuint program_id);
	virtual void fill_uniforms(GLuint program_id);
};