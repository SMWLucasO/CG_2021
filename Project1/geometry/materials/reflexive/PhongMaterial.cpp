#include "PhongMaterial.h"

PhongMaterial::PhongMaterial(): ReflexiveMaterial()
{
	this->shader_program = &Phong;
}

PhongMaterial::PhongMaterial(Light& light): ReflexiveMaterial(light)
{
}

void PhongMaterial::setup_uniforms(GLuint program_id)
{
	ReflexiveMaterial::setup_uniforms(program_id);
}

void PhongMaterial::send_uniforms(GLuint program_id)
{
	ReflexiveMaterial::send_uniforms(program_id);
}

void PhongMaterial::fill_uniforms(GLuint program_id)
{
	ReflexiveMaterial::fill_uniforms(program_id);
	uniform_specular = glGetUniformLocation(program_id, "mat_specular");
	uniform_material_power = glGetUniformLocation(program_id, "mat_power");
}
