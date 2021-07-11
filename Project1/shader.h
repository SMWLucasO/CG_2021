#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include "loaders/glsl/glsl.h"

#include "camera.h"
#include "lighting.h"

struct Uniforms
{
	// The location of our model + view matrices combined into one.
	GLuint uniform_mv;

	// The location of our projection matrix.
	GLuint uniform_p;
	GLuint uniform_proj;

	// The location of our light position
	GLuint uniform_light_pos;

	// The location of our specular
	GLuint uniform_specular;

	// The location of our material power, ambient and diffuse.
	GLuint uniform_material_power;
	GLuint uniform_material_ambient;
	GLuint uniform_material_diffuse;

	// The location of the boolean determining whether to render a texture.
	GLuint uniform_texture_enabled;
};

enum class ShaderType
{
	Lambert,
	Phong,
	Basic
};

class Shader
{
private:
	// The location of the shader program.
	GLuint program_id;

	// the uniforms
	Uniforms uniforms = Uniforms();

	/**
	* Initiate the shader.
	*
	* @param folder_name the folder in which the fragmentshader.frag and the vertexshader.vert are located.
	*/
	void init(std::string folder_name);
public:
	Shader();

	/**
	* Shader constructor.
	* 
	* @param folder_name the folder wherein the vertexshader.vert and fragmentshader.frag exist.
	*/
	Shader(std::string folder_name);

	/**
	* Get the uniforms of the shader program
	*
	* @return Uniform&
	*/
	Uniforms& get_uniforms();

	/**
	* Get the ID of this shader program.
	*
	* @return GLuint
	*/
	GLuint get_id();
};

