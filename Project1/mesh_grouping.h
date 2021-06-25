#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "entity.h"
#include "mesh.h"



class MeshGrouping: public Entity
{
private:
	std::vector<Mesh> entities;
public:

	void add(Mesh entity);

	void render();

	void setup();

};

