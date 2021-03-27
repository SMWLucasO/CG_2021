#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include "loaders/glsl/glsl.h"

#include "camera.h"
#include "lighting.h"

struct Uniforms {
	GLuint uniform_mv;
	GLuint uniform_p;
	GLuint uniform_proj;
	GLuint uniform_light_pos;
	GLuint uniform_specular;
	GLuint uniform_material_power;
	GLuint uniform_material_ambient;
	GLuint uniform_material_diffuse;
	GLuint uniform_texture_enabled;
};

enum class ShaderType{
	Lambert,
	Phong,
	Basic
};

class Shader
{
private:
	GLuint program_id;
	Uniforms uniforms = Uniforms();

	void init(std::string folder_name);
public:
	Shader();
	Shader(std::string folder_name);

	Uniforms& get_uniforms();
	GLuint get_id();
};

