// inspired by the following tutorials (the maths, mostly.)
// https://learnopengl.com/Getting-started/Camera
// http://tuttlem.github.io/2013/12/30/a-camera-implementation-in-c.html

#include "camera.h"

Camera* Camera::instance{ nullptr };

Camera::Camera()
{
}

Camera::~Camera()
{
	delete movement_controller;
	delete instance;
}

Camera* Camera::get_instance()
{

	// if our instance does not exist yet, create it.
	if (Camera::instance == nullptr)
		Camera::instance = new Camera();
	

	return Camera::instance;
}

glm::mat4 Camera::get_view()
{
	return glm::lookAt(
		this->position,
		this->position + this->target,
		this->up
	);
}

glm::vec3 Camera::get_position()
{
	return this->position;
}

glm::vec3 Camera::get_target()
{
	return this->target;
}

float Camera::get_yaw()
{
	return this->yaw;
}

float Camera::get_pitch()
{
	return this->pitch;
}

bool Camera::is_enabled()
{
	return this->enabled;
}

void Camera::set_enabled(bool enabled)
{
	this->enabled = enabled;
}

glm::mat4 Camera::get_projection()
{
	return this->projection;
}

void Camera::set_projection(glm::mat4 projection) {
	this->projection = projection;
}

void Camera::handle_keyboard(unsigned char key)
{
	// we switch between movement modes when the 'v' button has been pressed.
	if (key == 'v') {
		// we eventually want to delete our current movement controller, thus we keep a temporary pointer.
		MovementController* tmp = this->movement_controller;

		// We want to toggle between modes, the mode we are in is determined by the boolean drone_mode.
		if (drone_mode) {
			this->movement_controller = new ViewMovementController();
		}
		else {
			this->movement_controller = new DroneMovementController();
		}
		// toggle the boolean for drone mode.
		this->drone_mode = !drone_mode;

		// setup the movement controller.
		this->movement_controller->setup(this->position);
		
		// free memory.
		delete tmp;
	}
	else
	{
		// If the 'v' button wasn't pressed, then we handle the movement of our movement controller.
		this->movement_controller->handle_movement(key, this->position, this->up, this->target);
	}
}

void Camera::handle_mouse(int xpos, int ypos, int x_center, int y_center)
{
	if (!this->enabled) return; // only start working when enabled.
	// since we are locking in the center, all movements are calculated from this point.

	// we calculate the movement from the middle of our screen to the position where the mouse ended in this case.
	float xoffset = xpos - x_center;
	float yoffset = y_center - ypos; // reversed since y-coordinates range from bottom to top

	// limit the addition of degrees by the sensitivity, this way it isn't too fast.
	const float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	// Add the degrees to our pitch/yaw.
	yaw += xoffset;
	pitch += yoffset;

	// only want to look up and down, we don't want to rotate.
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	// calculate the new direction the camera is facing.
	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	this->target = glm::normalize(direction);

	// make sure that the mouse stays in the center of the screen.
	if (xpos != x_center || ypos != y_center)
		glutWarpPointer(x_center, y_center);
}
