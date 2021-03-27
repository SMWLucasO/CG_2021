#pragma once

#include <GL/glew.h>
#include "loaders/glsl/glsl.h"

enum class ShaderType{
	Lambert,
	Phong,
	Basic
};

class Shader
{
private:
	GLuint program_id;

	void init(std::string folder_name);
public:
	Shader();
	Shader(std::string folder_name);
	GLuint get_id();
};

