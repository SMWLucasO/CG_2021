#include "ReflexiveMaterial.h"

ReflexiveMaterial::ReflexiveMaterial()
{
}

ReflexiveMaterial::ReflexiveMaterial(Light& light)
{
	this->light = &light;
}

void ReflexiveMaterial::setup_uniforms(GLuint program_id)
{
	Material::setup_uniforms(program_id);
	uniform_light_pos = glGetUniformLocation(program_id, "light_pos");
	uniform_material_ambient = glGetUniformLocation(program_id, "mat_ambient");
	uniform_material_diffuse = glGetUniformLocation(program_id, "mat_diffuse");
}

void ReflexiveMaterial::send_uniforms(GLuint program_id)
{
	Material::send_uniforms(program_id);
}

void ReflexiveMaterial::fill_uniforms(GLuint program_id)
{
	Material::fill_uniforms(program_id);
	glUniform3fv(uniform_light_pos, 1, glm::value_ptr(light->get_position()));
	glUniform3fv(uniform_material_ambient, 1, glm::value_ptr(light->get_ambient_color()));
	glUniform3fv(uniform_material_diffuse, 1, glm::value_ptr(light->get_diffuse_color()));
}
