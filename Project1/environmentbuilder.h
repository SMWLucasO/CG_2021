#pragma once

#include <glm/glm.hpp>

#include "environmentmanager.h"

#include "geometry.h"
#include "floortile_geometry.h"

#include "mesh.h"
#include "mesh_grouping.h"

namespace builders::environment {

	void init();
	static void build_floor(int tilemap[][32], int rows, int columns);

	static void build_skybox();

	static void build_house(glm::vec3 position);

	static void build_fence(glm::vec3 position);

}