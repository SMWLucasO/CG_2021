#pragma once

#include <GL/glew.h>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
	glm::vec3 position = glm::vec3(-7, 0, 2);
	glm::vec3 target = glm::vec3(1, 0, -0.18);
	glm::vec3 up = glm::vec3(0, 1, 0);

	bool enabled = false;

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

	glm::vec3 get_position();
	glm::vec3 get_target();
	
	float get_yaw();
	float get_pitch();

	bool is_enabled();
	void set_enabled(bool enable);

	glm::mat4 get_projection();
	void set_projection(glm::mat4 projection);


	void handle_keyboard(unsigned char key, int a, int b);
	void handle_mouse(int xpos, int ypos, int x_center, int y_center);
};

