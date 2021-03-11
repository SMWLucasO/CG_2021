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
	float near = 0.5;
	float far = 100.0;

public:
	void set_position(glm::vec3 position);
	void process_mouse_movement();
};

