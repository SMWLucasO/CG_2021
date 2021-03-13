#include "Material.h"

ShaderProgram* Material::get_shader()
{
	return this->shader_program;
}

void Material::setup_uniforms(GLuint program_id)
{
	this->uniform_mv = glGetUniformLocation(program_id, "mv");
	this->uniform_projection = glGetUniformLocation(program_id, "projection");
}

void Material::fill_uniforms(GLuint program_id) {
	glUniformMatrix4fv(this->uniform_mv, 1, GL_FALSE, glm::value_ptr(this->mv));
	glUniformMatrix4fv(this->uniform_projection, 1, GL_FALSE, glm::value_ptr(this->projection));
}

void Material::send_uniforms(GLuint program_id)
{
	glUniformMatrix4fv(uniform_mv, 1, GL_FALSE, glm::value_ptr(this->mv));
	glUniformMatrix4fv(uniform_projection, 1, GL_FALSE, glm::value_ptr(this->projection));
}

void Material::set_model(glm::mat4 model)
{
	this->model = model;
	this->mv = this->view * model;
}

void Material::set_view(glm::mat4 view)
{
	this->view = view;
	this->mv = view * model;
}

void Material::set_projection(glm::mat4 projection)
{
	this->projection = projection;
}

Visual Material::get_visual()
{
	return this->visual;
}

void Material::set_visual(Visual visual)
{
	this->visual = visual;
}
