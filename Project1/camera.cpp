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
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
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
			position.z += 1;
			break;
		case 's':
			position.z -= 1;
			break;
		case 'a':
			position.x -= 1;
			break;
		case 'd':
			position.x += 1;
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
