#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "entity.h"
#include "mesh.h"



class MeshGrouping: public Entity
{
private:
	// the meshes in this mesh grouping.
	std::vector<Mesh*> entities;
public:

	/**
	* Add a mesh to the mesh grouping.
	*
	* @param mesh_to_add the mesh to add to the grouping.
	*/
	void add(Mesh* mesh_to_add);

	/**
	* Render the mesh grouping.
	*/
	void render();

	/**
	* Set up the mesh grouping.
	*/
	void setup();

};

