#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transformations {
public:
	// x/y/z scale transformation
	glm::vec3 scaling = glm::vec3(1, 1, 1);

	// x/y/z rotation transformation
	glm::vec3 rotations = glm::vec3(0, 0, 0);

	// x/y/z position transformation.
	glm::vec3 position = glm::vec3(0, 0, 0);

	/**
	* Get a matrix of all the applied transformations.
	*
	* @return glm::mat4
	*/
	glm::mat4 get_model();
};