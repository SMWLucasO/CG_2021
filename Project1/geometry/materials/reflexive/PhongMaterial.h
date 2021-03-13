#pragma once

#include "../../../shading/shading.h"
#include "ReflexiveMaterial.h"

#include <glm/glm.hpp>

class PhongMaterial: public ReflexiveMaterial {
private:
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;
public:
	PhongMaterial();
};