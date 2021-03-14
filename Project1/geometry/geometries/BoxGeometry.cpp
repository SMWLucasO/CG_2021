#include "BoxGeometry.h"

void BoxGeometry::render(Camera& camera, float screen_width, float screen_height) {
	Geometry::render(camera, screen_width, screen_height);
}

void BoxGeometry::init() {
	// box points
	this->vertices.push_back(glm::vec3(-1.0, -1.0, 1.0));
	this->vertices.push_back(glm::vec3(1.0, -1.0, 1.0));
	this->vertices.push_back(glm::vec3(1.0, 1.0, 1.0));
	this->vertices.push_back(glm::vec3(-1.0, 1.0, 1.0));
	this->vertices.push_back(glm::vec3(-1.0, -1.0, -1.0));
	this->vertices.push_back(glm::vec3(1.0, -1.0, -1.0));
	this->vertices.push_back(glm::vec3(1.0, 1.0, -1.0));
	this->vertices.push_back(glm::vec3(-1.0, 1.0, -1.0));

	// ibo's
	this->faces.push_back(glm::vec3(0, 1, 5));
	this->faces.push_back(glm::vec3(0, 4, 5));
	this->faces.push_back(glm::vec3(4, 5, 6));
	this->faces.push_back(glm::vec3(4, 6, 7));
	this->faces.push_back(glm::vec3(1, 5, 6));
	this->faces.push_back(glm::vec3(1, 2, 6));
	this->faces.push_back(glm::vec3(0, 4, 7));
	this->faces.push_back(glm::vec3(0, 3, 7));
	this->faces.push_back(glm::vec3(3, 2, 6));
	this->faces.push_back(glm::vec3(3, 6, 7));
	this->faces.push_back(glm::vec3(0, 1, 2));
	this->faces.push_back(glm::vec3(0, 2, 3));

	ColorVisual tmp_visual = ColorVisual();
	tmp_visual.set_color(this->vertices.size(), glm::vec3(1.0, 0.0, 0.0));

	this->get_material().set_visual(tmp_visual);
}