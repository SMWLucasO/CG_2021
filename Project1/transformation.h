#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transformations {
public:
	glm::vec3 scaling = glm::vec3(1, 1, 1);
	glm::vec3 rotations = glm::vec3(0, 0, 0);
	glm::vec3 position = glm::vec3(0, 0, 0);

	glm::mat4 get_model();
};