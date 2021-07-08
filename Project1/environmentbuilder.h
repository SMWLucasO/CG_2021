#pragma once

#include <glm/glm.hpp>

#include "environmentmanager.h"

#include "geometry.h"
#include "floortile_geometry.h"

#include "mesh.h"
#include "mesh_grouping.h"

namespace builders::environment {

	void init();
	static MeshGrouping& build_floor(int tilemap[][32], int rows, int columns);

	static Mesh& build_skybox();

	static MeshGrouping& build_house(glm::vec3 position);

	static MeshGrouping& build_fence(glm::vec3 position);

	static MeshGrouping& build_tree(glm::vec3 position);
	static MeshGrouping& build_dead_tree(glm::vec3 position);
	
	static MeshGrouping& build_flower(glm::vec3 position);

	static MeshGrouping& build_stemmed_bush(glm::vec3 position);
	static MeshGrouping& build_fruit_bush(glm::vec3 position);
	
	static MeshGrouping& build_bird(glm::vec3 position);

	static MeshGrouping& build_couch(glm::vec3 position);

}