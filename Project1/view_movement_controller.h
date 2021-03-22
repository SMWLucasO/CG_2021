#pragma once

#include <GL/glew.h>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "movement_controller.h"


class ViewMovementController: public MovementController
{
public:
	void setup(glm::vec3& position);
	void handle_movement(unsigned char key, glm::vec3& position, glm::vec3 up, glm::vec3 target);
};

