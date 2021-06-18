#include "cube_geometry.h"

CubeGeometry::CubeGeometry()
{
	// vertices:
	// 1 = 1.0, 1.0, -1.0
	// 2 = 1.0, -1.0, -1.0
	// 3 = 1.0, 1.0, 1.0
	// 4 = 1.0, -1.0, 1.0
	// 5 = -1.0, 1.0, -1.0
	// 6 = -1.0, -1.0, -1.0
	// 7 = -1.0, 1.0, 1.0
	// 8 = -1.0, -1.0, 1.0
	vertices.push_back(glm::vec3(-1.0, 1.0, -1.0));
	vertices.push_back(glm::vec3(1.0, 1.0, 1.0));
	vertices.push_back(glm::vec3(1.0, 1.0, -1.0));

	vertices.push_back(glm::vec3(1.0, 1.0, 1.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, 1.0));
	vertices.push_back(glm::vec3(1.0, -1.0, 1.0));

	vertices.push_back(glm::vec3(-1.0, 1.0, 1.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, -1.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, 1.0));

	vertices.push_back(glm::vec3(1.0, -1.0, -1.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, 1.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, -1.0));

	vertices.push_back(glm::vec3(1.0, 1.0, -1.0));
	vertices.push_back(glm::vec3(1.0, -1.0, 1.0));
	vertices.push_back(glm::vec3(1.0, -1.0, -1.0));

	vertices.push_back(glm::vec3(-1.0, 1.0, -1.0));
	vertices.push_back(glm::vec3(1.0, -1.0, -1.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, -1.0));

	vertices.push_back(glm::vec3(-1.0, 1.0, -1.0));
	vertices.push_back(glm::vec3(-1.0, 1.0, 1.0));
	vertices.push_back(glm::vec3(1.0, 1.0, 1.0));

	vertices.push_back(glm::vec3(1.0, 1.0, 1.0));
	vertices.push_back(glm::vec3(-1.0, 1.0, 1.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, 1.0));

	vertices.push_back(glm::vec3(-1.0, 1.0, 1.0));
	vertices.push_back(glm::vec3(-1.0, 1.0, -1.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, -1.0));

	vertices.push_back(glm::vec3(1.0, -1.0, -1.0));
	vertices.push_back(glm::vec3(1.0, -1.0, 1.0));
	vertices.push_back(glm::vec3(-1.0, -1.0, 1.0));

	vertices.push_back(glm::vec3(1.0, 1.0, -1.0));
	vertices.push_back(glm::vec3(1.0, 1.0, 1.0));
	vertices.push_back(glm::vec3(1.0, -1.0, 1.0));

	vertices.push_back(glm::vec3(-1.0, 1.0, -1.0));
	vertices.push_back(glm::vec3(1.0, 1.0, -1.0));
	vertices.push_back(glm::vec3(1.0, -1.0, -1.0));


	// uvs:
	//  


}
