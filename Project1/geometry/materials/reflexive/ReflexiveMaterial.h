#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "../Material.h"

class ReflexiveMaterial: public Material
{
private:
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
public:
};

