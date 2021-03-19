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

void Camera::handle_keyboard(unsigned char key, int a, int b)
{
	switch (key) {
		case 'w':
			position += this->target;
			break;
		case 's':
			position -= this->target;
			break;
		case 'a':
			position -= glm::normalize(glm::cross(this->target, this->up));
			break;
		case 'd':
			position += glm::normalize(glm::cross(this->target, this->up));
			break;
		case 'q':	
			position.y -= 1;
			break;
		case 'e':
			position.y += 1;
			break;
	}

	// W/A/S/D for movement
	// i/j/k/l for look around / change directions
	// q/e for down/up
	// r for reloading json data.
}

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
