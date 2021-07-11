#pragma once

#include <GL/glew.h>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "movement_controller.h"

class DroneMovementController: public MovementController
{
public:
	void setup(glm::vec3& position, float& pitch, float& yaw);

	/**
	* Handle the movement for the drone camera.
	*
	* @param key the pressed key.
	* @param position the current position of the camera
	* @param up the 'up' of the camera.
	* @param target the location we are looking towards
	*/
	void handle_movement(unsigned char key, glm::vec3& position, glm::vec3 up, glm::vec3 target);
};

