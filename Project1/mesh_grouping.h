#pragma once

#include <vector>

#include "entity.h"
#include "mesh.h"

class MeshGrouping: public Entity
{
private:
	glm::vec3 position = glm::vec3(0,0,0);
	std::vector<Mesh> entities;
public:

	void add(Mesh entity);

	void render();

	void setup();

};

