#include "shader.h"

Shader::Shader(const std::string folder_name)
{
	this->init(folder_name);
}

// in case this one is used, init must be called manually.
Shader::Shader()
{

}

void Shader::init(std::string folder_name)
{
	// generate the vertex shader
    char* vertexshader = glsl::readFile((folder_name + "vertexshader.vert").c_str());
    GLuint vsh_id = glsl::makeVertexShader(vertexshader);

	// generate the fragment shader
    char* fragshader = glsl::readFile((folder_name + "fragmentshader.frag").c_str());
    GLuint fsh_id = glsl::makeFragmentShader(fragshader);

	// create a shader program using the vertex- and fragmentshader.
    program_id = glsl::makeShaderProgram(vsh_id, fsh_id);

	// set the locations for sending the uniforms to the shading program.
	// see: https://docs.gl/gl3/glGetUniformLocation
	uniforms.uniform_mv = glGetUniformLocation(program_id, "mv");
	uniforms.uniform_proj = glGetUniformLocation(program_id, "projection");
	uniforms.uniform_light_pos = glGetUniformLocation(program_id, "light_pos");
	uniforms.uniform_specular = glGetUniformLocation(program_id, "mat_specular");
	uniforms.uniform_material_power = glGetUniformLocation(program_id, "mat_power");
	uniforms.uniform_material_ambient = glGetUniformLocation(program_id, "mat_ambient");
	uniforms.uniform_material_diffuse = glGetUniformLocation(program_id, "mat_diffuse");
	uniforms.uniform_texture_enabled = glGetUniformLocation(program_id, "texture_enabled");

	// use the shdaer program and send the projection uniform & position of the light.
	glUseProgram(program_id);

	Lighting* lighting = Lighting::get_instance();

	glUniformMatrix4fv(uniforms.uniform_proj, 1, GL_FALSE, glm::value_ptr(Camera::get_instance()->get_projection()));
	glUniform3fv(uniforms.uniform_light_pos, 1, glm::value_ptr(lighting->get_position()));
}

Uniforms& Shader::get_uniforms()
{
	return this->uniforms;
}

GLuint Shader::get_id()
{
    return this->program_id;
}
