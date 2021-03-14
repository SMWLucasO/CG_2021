#include "LambertMaterial.h"

LambertMaterial::LambertMaterial(): ReflexiveMaterial()
{
	this->shader_program = &Lambert;
}

LambertMaterial::LambertMaterial(Light& light): ReflexiveMaterial(light)
{

}

void LambertMaterial::setup_uniforms(GLuint program_id)
{
	ReflexiveMaterial::setup_uniforms(program_id);
}

void LambertMaterial::send_uniforms(GLuint program_id)
{
	ReflexiveMaterial::send_uniforms(program_id);
}

void LambertMaterial::fill_uniforms(GLuint program_id)
{
	ReflexiveMaterial::fill_uniforms(program_id);
}
