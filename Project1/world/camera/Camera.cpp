#include "Camera.h"

void Camera::set_position(glm::vec3 position) {
	this->position = position;
}

void Camera::process_mouse_movement() {

}

glm::vec3 Camera::get_position()
{
	return this->position;
}

glm::vec3 Camera::get_target()
{
	return this->target;
}

glm::vec3 Camera::get_camera_up()
{
	return this->up;
}

float Camera::get_fov()
{
	return this->FOV;
}

float Camera::get_cam_near()
{
	return this->cam_near;
}

float Camera::get_cam_far()
{
	return this->cam_far;
}

void Camera::set_fov(float fov)
{
	this->FOV = fov;
}

void Camera::set_cam_near(float cam_near)
{
	this->cam_near = cam_near;
}

void Camera::set_cam_far(float cam_far)
{
	this->cam_far = cam_far;
}

void Camera::set_target(glm::vec3 target)
{
	this->target = target;
}

void Camera::set_cam_up(glm::vec3 cam_up)
{
	this->up = cam_up;
}
