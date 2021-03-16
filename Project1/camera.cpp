#include "camera.h"

Camera* Camera::instance{ nullptr };
std::mutex Camera::_mutex;

Camera::Camera()
{
}

Camera::~Camera()
{
	delete instance;
}

Camera* Camera::get_instance() {

	std::lock_guard<std::mutex> lock(_mutex);

	if (Camera::instance == nullptr) {
		Camera::instance = new Camera();
	}

	return Camera::instance;
}

glm::mat4 Camera::get_view()
{
	return glm::mat4();
}

glm::mat4 Camera::get_projection()
{
	return this->projection;
}

void Camera::set_projection(glm::mat4 projection) {
	this->projection = projection;
}

void Camera::handle_keyboard(int keycode)
{
}

void Camera::handle_mouse()
{
}
