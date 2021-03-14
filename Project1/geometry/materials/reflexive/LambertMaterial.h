#pragma once

#include "../../../shading/shading.h"
#include "ReflexiveMaterial.h"

class LambertMaterial: public ReflexiveMaterial {
private:
public:
	LambertMaterial();
	LambertMaterial(Light& light);
	virtual void setup_uniforms(GLuint program_id);
	virtual void send_uniforms(GLuint program_id);
	virtual void fill_uniforms(GLuint program_id);
};