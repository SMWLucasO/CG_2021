#include "walk_movement_controller.h"

void WalkMovementController::setup(glm::vec3& position, float& pitch, float& yaw)
{
	position = glm::vec3(20.40, 1.5, 18.5);

	pitch = -3.6;
	yaw = 150.4;

}

void WalkMovementController::handle_movement(unsigned char key, glm::vec3& position, glm::vec3 up, glm::vec3 target)
{

	// set target.y to 0 so that it will no longer move in the y-direction using the camera.
	target.y = 0;

	glm::vec3 new_position(position.x, position.y, position.z);
	switch (key)
	{
	case 'w':
		// go towards our direction
		new_position += target;
		break;
	case 's':
		// move away from our direction
		new_position -= target;
		break;
	case 'a':
		// move left relative to our direction.
		new_position -= glm::normalize(glm::cross(target, up));
		break;
	case 'd':
		// move right relative to our direction.
		new_position += glm::normalize(glm::cross(target, up));
		break;
	}

	// Make sure that we do not go below the lowest point as determined by the Y_LOWEST_POINT const.
	if (new_position.y < MovementController::Y_LOWEST_POINT)
		new_position.y = MovementController::Y_LOWEST_POINT;

	position = new_position;

}
