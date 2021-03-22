#include "view_movement_controller.h"

void ViewMovementController::setup(glm::vec3& position)
{
	position = glm::vec3(0, 0, 0); // TODO set better position
}

void ViewMovementController::handle_movement(unsigned char key, glm::vec3& position, glm::vec3 up, glm::vec3 target)
{

	// set target.y to 0 so that it will no longer move in the y-direction using the camera.
	target.y = 0;

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
	}

	if (new_position.y < MovementController::Y_LOWEST_POINT)
		new_position.y = MovementController::Y_LOWEST_POINT;

	position = new_position;

}
