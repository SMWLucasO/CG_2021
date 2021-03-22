#pragma once

#include <glm/glm.hpp>

class MovementController
{
public:
	static const int Y_LOWEST_POINT = 0;
	virtual void setup(glm::vec3& position) = 0;
	virtual void handle_movement(unsigned char key, glm::vec3& position, glm::vec3 up, glm::vec3 target) = 0;
};

