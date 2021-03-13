#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../loaders/glsl/glsl.h"

struct ShaderProgram {
	GLuint vsh_id;
	GLuint fsh_id;
	GLuint program_id;
};

extern ShaderProgram Phong, Lambert, Basic;

void init_shader(ShaderProgram& shader, const char* vertexshader_name, const char* fragshader_name);