#include "drone_movement_controller.h"

void DroneMovementController::setup(glm::vec3& position, float& pitch, float& yaw)
{
	position = glm::vec3(44.63, 25.62, 67.20); // give it a good overview.

	pitch = -25.2;
	yaw = -134.3;
}

void DroneMovementController::handle_movement(unsigned char key, glm::vec3& position, glm::vec3 up, glm::vec3 target)
{
	glm::vec3 new_position(position.x, position.y, position.z);
	switch (key)
	{
		case 'w':
			// move towards the direction we are facing
			new_position += target;
			break;
		case 's':
			// move away from the direction we are facing.
			new_position -= target;
			break;
		case 'a':
			// move to the left relative to our camera direction.
			new_position -= glm::normalize(glm::cross(target, up));
			break;
		case 'd':
			// move to the right relative to our camera direction.
			new_position += glm::normalize(glm::cross(target, up));
			break;
		case 'q':
			// Move up.
			new_position.y += Y_INCREMENT;
			break;
		case 'e':
			// move down
			new_position.y -= Y_INCREMENT;
			break;
	}

	position = new_position;
}