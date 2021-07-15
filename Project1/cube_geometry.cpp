#include "cube_geometry.h"

CubeGeometry::CubeGeometry()
{
	// front
	this->vertices.push_back(glm::vec3(0,0,0));
	this->vertices.push_back(glm::vec3(1,0,0));
	this->vertices.push_back(glm::vec3(1,1,0));

	this->vertices.push_back(glm::vec3(0,0,0));
	this->vertices.push_back(glm::vec3(0,1,0));
	this->vertices.push_back(glm::vec3(1,1,0));

	// normals for front
	for (int i = 0; i < 6; i++)
		this->normals.push_back(glm::vec3(0, 0, -1));

	// bottom
	this->vertices.push_back(glm::vec3(0, 0, 0));
	this->vertices.push_back(glm::vec3(1, 0, 1));
	this->vertices.push_back(glm::vec3(0, 0, 1));

	this->vertices.push_back(glm::vec3(0, 0, 0));
	this->vertices.push_back(glm::vec3(1, 0, 0));
	this->vertices.push_back(glm::vec3(1, 0, 1));

	// normals for bottom
	for (int i = 0; i < 6; i++)
		this->normals.push_back(glm::vec3(0, -1, 0));

	// left
	this->vertices.push_back(glm::vec3(0, 0, 0));
	this->vertices.push_back(glm::vec3(0, 0, 1));
	this->vertices.push_back(glm::vec3(0, 1, 1));

	this->vertices.push_back(glm::vec3(0, 0, 0));
	this->vertices.push_back(glm::vec3(0, 1, 0));
	this->vertices.push_back(glm::vec3(0, 1, 1));

	// normals for left
	for (int i = 0; i < 6; i++)
		this->normals.push_back(glm::vec3(-1, 0, 0));

	// right
	this->vertices.push_back(glm::vec3(1, 0, 0));
	this->vertices.push_back(glm::vec3(1, 0, 1));
	this->vertices.push_back(glm::vec3(1, 1, 1));

	this->vertices.push_back(glm::vec3(1, 0, 0));
	this->vertices.push_back(glm::vec3(1, 1, 0));
	this->vertices.push_back(glm::vec3(1, 1, 1));

	// normals for right
	for (int i = 0; i < 6; i++)
		this->normals.push_back(glm::vec3(1, 0, 0));

	// back
	this->vertices.push_back(glm::vec3(0, 0, 1));
	this->vertices.push_back(glm::vec3(1, 0, 1));
	this->vertices.push_back(glm::vec3(1, 1, 1));

	this->vertices.push_back(glm::vec3(0, 0, 1));
	this->vertices.push_back(glm::vec3(0, 1, 1));
	this->vertices.push_back(glm::vec3(1, 1, 1));

	// normals for back
	for (int i = 0; i < 6; i++)
		this->normals.push_back(glm::vec3(0, 0, 1));

	// top
	this->vertices.push_back(glm::vec3(0, 1, 0));
	this->vertices.push_back(glm::vec3(1, 1, 0));
	this->vertices.push_back(glm::vec3(1, 1, 1));

	this->vertices.push_back(glm::vec3(0, 1, 0));
	this->vertices.push_back(glm::vec3(0, 1, 1));
	this->vertices.push_back(glm::vec3(1, 1, 1));

	// normals for top
	for (int i = 0; i < 6; i++)
		this->normals.push_back(glm::vec3(0, 1, 0));

	for (int i = 0; i < 36; i++)
		this->uvs.push_back(glm::vec2(0, 0));

}
