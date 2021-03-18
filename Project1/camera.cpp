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
	// inspired by the following tutorial (the maths, mostly.)
	// http://tuttlem.github.io/2013/12/30/a-camera-implementation-in-c.html
	switch (key) {
		case 'w':
			position += this->target;
			break;
		case 's':
			position -= this->target;
			break;
		case 'a':
			
			break;
		case 'd':
			
			break;
		case 'i':
			break;
		case 'j':
			break;
		case 'k':
			break;
		case 'l':
			break;
	}

	// W/A/S/D for movement
	// i/j/k/l for look around / change directions
	// r for reloading json data.
}
