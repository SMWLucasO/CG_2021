#include "drone_movement_controller.h"

void DroneMovementController::setup(glm::vec3& position)
{
	position = glm::vec3(0, 0, 0); // give it a good overview.
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
			// Move down depending on whether the camera is still above or on the lowest point afterwards.
			if (position.y - MovementController::Y_INCREMENT >= MovementController::Y_LOWEST_POINT)
				new_position.y -= Y_INCREMENT;
			break;
	}

	// make sure that the camera cannot go below the lowest Y point.
	if (new_position.y < MovementController::Y_LOWEST_POINT)
		new_position.y = MovementController::Y_LOWEST_POINT;

	position = new_position;
}