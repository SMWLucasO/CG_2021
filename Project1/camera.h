#pragma once

#include <mutex>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera
{
private:
	glm::vec3 position;

	float yaw;
	float pitch;

	// it's here for now, perhaps not the right place. Idk.
	glm::mat4 projection;

	static Camera* instance;
	static std::mutex _mutex;

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


	void handle_keyboard(int keycode);
	void handle_mouse();
};

