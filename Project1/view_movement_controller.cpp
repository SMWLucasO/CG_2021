#include "view_movement_controller.h"

void ViewMovementController::setup(glm::vec3& position)
{
	// camera position and angle must stay the same. Thus, don't change anything
	// ^idk, what is view mode?
}

/**
* Handle the movement for the view camera.
*
* @param key the pressed key.
* @param position the current position of the camera
* @param up the 'up' of the camera.
* @param target the location we are looking towards
*/
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
