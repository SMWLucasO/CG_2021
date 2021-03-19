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
		case 'i':
			break;
		case 'j':
			break;
		case 'k':
			break;
		case 'l':
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
	// r for reloading json data.
}
