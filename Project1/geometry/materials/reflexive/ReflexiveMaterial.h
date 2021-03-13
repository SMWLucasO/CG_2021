#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "../Material.h"

class ReflexiveMaterial: public Material
{
private:
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
public:
	virtual void setup_uniforms(GLuint program_id);
	virtual void send_uniforms(GLuint program_id);
	virtual void fill_uniforms(GLuint program_id);
};

