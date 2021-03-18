#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
	glm::vec3 position = glm::vec3(-3, 5, 0);
	glm::vec3 target = glm::vec3(0, 0, -1);
	glm::vec3 up = glm::vec3(0, 1, 0);

	float yaw = 0;
	float pitch = 0;

	glm::mat4 projection;

	static Camera* instance;

	Camera();
	~Camera();

public:

	Camera(Camera& camera) = delete;
	Camera(const Camera& camera) = delete;

	void operator =(const Camera&) = delete;

	static Camera* get_instance();

	glm::mat4 get_view();
	
	glm::mat4 get_projection();
	void set_projection(glm::mat4 projection);

	void handle_keyboard(unsigned char key, int a, int b);
};

