#include "skyboxright_geometry.h"

SkyboxRightGeometry::SkyboxRightGeometry()
{
	vertices.push_back(glm::vec3(1.0, -1.0, 0.0));
	vertices.push_back(glm::vec3(-1.0, 1.0, 0.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, 0.0));
	vertices.push_back(glm::vec3(1.0, -1.0, 0.0));
	vertices.push_back(glm::vec3(1.0, 1.0, 0.0));
	vertices.push_back(glm::vec3(-1.0, 1.0, 0.0));

	normals.push_back(glm::vec3(0.0, 0.0, 1.0));
	normals.push_back(glm::vec3(0.0, 0.0, 1.0));
	normals.push_back(glm::vec3(0.0, 0.0, 1.0));
	normals.push_back(glm::vec3(0.0, 0.0, 1.0));
	normals.push_back(glm::vec3(0.0, 0.0, 1.0));
	normals.push_back(glm::vec3(0.0, 0.0, 1.0));

	uvs.push_back(glm::vec2(1.0, 0.0));
	uvs.push_back(glm::vec2(0.0, 1.0));
	uvs.push_back(glm::vec2(0.0, 0.0));
	uvs.push_back(glm::vec2(1.0, 0.0));
	uvs.push_back(glm::vec2(1.0, 1.0));
	uvs.push_back(glm::vec2(0.0, 1.0));
}
