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

	if (Camera::instance == nullptr) {
		Camera::instance = new Camera();
	}

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

void Camera::set_enabled(bool enable)
{
	this->enabled = enable;
}

glm::mat4 Camera::get_projection()
{
	return this->projection;
}

void Camera::set_projection(glm::mat4 projection) {
	this->projection = projection;
}


/**
* Handle the keyboard pressed events for the camera.
* 
* @param key the key pressed
*/
void Camera::handle_keyboard(unsigned char key)
{
	if (key == 'v') {
		MovementController* tmp = this->movement_controller;
		if (drone_mode) {
			this->movement_controller = new ViewMovementController();
		}
		else {
			this->movement_controller = new DroneMovementController();
		}
		this->drone_mode = !drone_mode;
		this->movement_controller->setup(this->position);
		delete tmp;
	}
	else {
		this->movement_controller->handle_movement(key, this->position, this->up, this->target);
	}

	// W/A/S/D for movement
	// q/e for down/up
	// r for reloading json data.
}

/**
* Handle the mouse movement for the camera.
*
* Deals with the direction which the camera is facing.
*
* @param xpos the x-position moved towards
* @param ypos the y-position moved towards
* @param x_center the x-center of the screen
* @param y_center the y-center of the screen
*/
void Camera::handle_mouse(int xpos, int ypos, int x_center, int y_center)
{
	if (!this->enabled) return; // only start working when enabled.
	// since we are locking in the center, all movements are calculated from this point.
	float xoffset = xpos - x_center;
	float yoffset = y_center - ypos; // reversed since y-coordinates range from bottom to top

	const float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	// only want to look up and down, we don't want to rotate.
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	this->target = glm::normalize(direction);

	if (xpos != x_center || ypos != y_center)
		glutWarpPointer(x_center, y_center);
}
