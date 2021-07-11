#include "floortile_geometry.h"

FloorTileGeometry::FloorTileGeometry()
{

	// add the vertices to the primitive geometry.
	vertices.push_back(glm::vec3(1.0, 0.0, 1.0));
	vertices.push_back(glm::vec3(-1.0, 0.0, -1.0));
	vertices.push_back(glm::vec3(-1.0, 0.0, 1.0));
	vertices.push_back(glm::vec3(1.0, 0.0, 1.0));
	vertices.push_back(glm::vec3(1.0, 0.0, -1.0));
	vertices.push_back(glm::vec3(-1.0, 0.0, -1.0));

	// add the normals to the primitive geometry.
	normals.push_back(glm::vec3(0.0, 1.0, 0.0));
	normals.push_back(glm::vec3(0.0, 1.0, 0.0));
	normals.push_back(glm::vec3(0.0, 1.0, 0.0));
	normals.push_back(glm::vec3(0.0, 1.0, 0.0));
	normals.push_back(glm::vec3(0.0, 1.0, 0.0));
	normals.push_back(glm::vec3(0.0, 1.0, 0.0));

	// add the UVs to the primitive geometry.
	uvs.push_back(glm::vec2(0.0, 1.0));
	uvs.push_back(glm::vec2(1.0, 0.0));
	uvs.push_back(glm::vec2(1.0, 1.0));
	uvs.push_back(glm::vec2(0.0, 1.0));
	uvs.push_back(glm::vec2(0.0, 0.0));
	uvs.push_back(glm::vec2(1.0, 0.0));
}
