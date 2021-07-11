#pragma once

#include <GL/glew.h>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "movement_controller.h"
#include "drone_movement_controller.h"
#include "view_movement_controller.h"

class Camera
{
private:
	// The position which the camera is currently at.
	glm::vec3 position = glm::vec3(0, 1, 0);

	// The direction which the camera is currently pointing at.
	glm::vec3 target = glm::vec3(1, 0, -0.18);

	// The 'up' direction for the camera. Our Y-axis is our up-axis.
	glm::vec3 up = glm::vec3(0, 1, 0);

	// The camera is disabled until you click on the screen
	bool enabled = false;

	// yaw => look left/right
	float yaw = 0;
	
	// pitch => look up/down
	float pitch = 0;

	// true if we're in drone mode, false otherwise.
	bool drone_mode = true;

	// The camera's projection matrix.
	glm::mat4 projection;

	// The single camera instance.
	static Camera* instance;

	// The movement handler for the camera.
	MovementController* movement_controller = new DroneMovementController();

	Camera();
	~Camera();

public:
	Camera(Camera& camera) = delete;
	Camera(const Camera& camera) = delete;

	void operator =(const Camera&) = delete;

	/**
	* Get the single instance of the camera.
	*
	* @return Camera*
	*/
	static Camera* get_instance();

	/**
	* Get the view matrix of the camera.
	* 
	* @return glm::mat4
	*/
	glm::mat4 get_view();

	/**
	* Get the current position of the camera.
	*
	* @return glm::vec3
	*/
	glm::vec3 get_position();

	/**
	* Get the direction the camera is facing.
	*
	* @return glm::vec3
	*/
	glm::vec3 get_target();
	
	/**
	* Get the current yaw of the camera.
	*
	* @return float
	*/
	float get_yaw();

	/**
	* Get the current pitch of the camera.
	*
	* @return float
	*/
	float get_pitch();

	/**
	* Check whether the camera is enabled.
	*
	* @return bool
	*/
	bool is_enabled();

	/**
	* Enable or disable the camera. Setting this to false locks the camera in place.
	* 
	* @param enabled boolean determining whether the camera is enabled.
	*/
	void set_enabled(bool enabled);

	/**
	* Get the camera's projection matrix.
	*
	* @returns glm::mat4
	*/
	glm::mat4 get_projection();

	/**
	* Set the camera's projection matrix.
	* 
	* @param projection the projection matrix to be set.
	*/
	void set_projection(glm::mat4 projection);

	/**
	* Handle the keyboard pressed events for the camera.
	*
	* @param key the key pressed
	*/
	void handle_keyboard(unsigned char key);

	/**
	* Handle the mouse movement for the camera.
	*
	* Deals with the direction which the camera is facing.
	*
	* @param xpos the x-position moved towards
	* @param ypos the y-position moved towards
	* @param x_center the x-center of the screen
	* @param y_center the y-center of the screen
	*/
	void handle_mouse(int xpos, int ypos, int x_center, int y_center);

};

