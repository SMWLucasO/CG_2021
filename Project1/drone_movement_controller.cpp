#include "drone_movement_controller.h"

void DroneMovementController::setup(glm::vec3& position)
{
	position = glm::vec3(0, 0, 0); // give it a good overview.
}

/**
* Handle the movement for the drone camera.
* 
* @param key the pressed key.
* @param position the current position of the camera
* @param up the 'up' of the camera.
* @param target the location we are looking towards
*/
void DroneMovementController::handle_movement(unsigned char key, glm::vec3& position, glm::vec3 up, glm::vec3 target)
{
	glm::vec3 new_position(position.x, position.y, position.z);
	switch (key)
	{
		case 'w':
			new_position += target;
			break;
		case 's':
			new_position -= target;
			break;
		case 'a':
			new_position -= glm::normalize(glm::cross(target, up));
			break;
		case 'd':
			new_position += glm::normalize(glm::cross(target, up));
			break;
		case 'q':
			if (position.y + MovementController::Y_INCREMENT >= MovementController::Y_LOWEST_POINT)
				new_position.y += Y_INCREMENT;
			break;
		case 'e':
			if (position.y - MovementController::Y_INCREMENT >= MovementController::Y_LOWEST_POINT)
				new_position.y -= Y_INCREMENT;
			break;
	}

	if (new_position.y < MovementController::Y_LOWEST_POINT)
		new_position.y = MovementController::Y_LOWEST_POINT;

	position = new_position;
}