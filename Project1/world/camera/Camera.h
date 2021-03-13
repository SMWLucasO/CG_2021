#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 up;
	float FOV = 45.0;
	float cam_near = 0.5;
	float cam_far = 100.0;

public:
	glm::vec3 get_position();
	glm::vec3 get_target();
	glm::vec3 get_camera_up();

	float get_fov();
	float get_cam_near();
	float get_cam_far();

	void set_fov(float fov);
	void set_cam_near(float cam_near);
	void set_cam_far(float cam_far);

	void set_target(glm::vec3 target);
	void set_cam_up(glm::vec3 cam_up);
	void set_position(glm::vec3 position);
	
	void process_mouse_movement();
};

