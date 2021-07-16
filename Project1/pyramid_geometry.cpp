#include "pyramid_geometry.h"

PyramidGeometry::PyramidGeometry()
{
	// left
	this->vertices.push_back(glm::vec3(0, 0, 0));
	this->vertices.push_back(glm::vec3(0, 0, 1));
	this->vertices.push_back(glm::vec3(0.5, 1, 0.5));

	this->uvs.push_back(glm::vec2(1, 0));
	this->uvs.push_back(glm::vec2(0, 0));
	this->uvs.push_back(glm::vec2(1, 1));
	
	// normals for left
	for (int i = 0; i < 3; i++)
		this->normals.push_back(glm::vec3(-1, 1, 0));

	// front
	this->vertices.push_back(glm::vec3(0, 0, 0));
	this->vertices.push_back(glm::vec3(1, 0, 0));
	this->vertices.push_back(glm::vec3(0.5, 1, 0.5));

	this->uvs.push_back(glm::vec2(0, 0));
	this->uvs.push_back(glm::vec2(1, 0));
	this->uvs.push_back(glm::vec2(1, 1));

	// normals for front
	for (int i = 0; i < 3; i++)
		this->normals.push_back(glm::vec3(0, 1, -1));
	
	// back
	this->vertices.push_back(glm::vec3(0, 0, 1));
	this->vertices.push_back(glm::vec3(1, 0, 1));
	this->vertices.push_back(glm::vec3(0.5, 1, 0.5));

	this->uvs.push_back(glm::vec2(1, 0));
	this->uvs.push_back(glm::vec2(0, 0));
	this->uvs.push_back(glm::vec2(0, 1));

	// normals for back
	for (int i = 0; i < 3; i++)
		this->normals.push_back(glm::vec3(0, 1, 1));

	// right
	this->vertices.push_back(glm::vec3(1, 0, 0));
	this->vertices.push_back(glm::vec3(1, 0, 1));
	this->vertices.push_back(glm::vec3(0.5, 1, 0.5));

	this->uvs.push_back(glm::vec2(0, 0));
	this->uvs.push_back(glm::vec2(1, 0));
	this->uvs.push_back(glm::vec2(1, 1));

	// normals for bottom
	for (int i = 0; i < 3; i++)
		this->normals.push_back(glm::vec3(1, 1, 0));

	// bottom
	this->vertices.push_back(glm::vec3(0, 0, 0));
	this->vertices.push_back(glm::vec3(1, 0, 1));
	this->vertices.push_back(glm::vec3(0, 0, 1));

	this->vertices.push_back(glm::vec3(0, 0, 0));
	this->vertices.push_back(glm::vec3(1, 0, 0));
	this->vertices.push_back(glm::vec3(1, 0, 1));

	this->uvs.push_back(glm::vec2(0, 0));
	this->uvs.push_back(glm::vec2(1, 1));
	this->uvs.push_back(glm::vec2(0, 1));

	this->uvs.push_back(glm::vec2(0, 0));
	this->uvs.push_back(glm::vec2(1, 0));
	this->uvs.push_back(glm::vec2(1, 1));

	// normals for bottom
	for (int i = 0; i < 6; i++)
		this->normals.push_back(glm::vec3(0, -1, 0));
}
