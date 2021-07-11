#include "view_movement_controller.h"

void ViewMovementController::setup(glm::vec3& position)
{
	// camera position and angle must stay the same. Thus, don't change anything
	// ^idk, what is view mode?
}

void ViewMovementController::handle_movement(unsigned char key, glm::vec3& position, glm::vec3 up, glm::vec3 target)
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
