#pragma once

#include <glm/glm.hpp>

#include "environmentmanager.h"

#include "geometry.h"
#include "floortile_geometry.h"

#include "mesh.h"
#include "mesh_grouping.h"

namespace builders::environment {

	void init();
	static void build_floor(int** tilemap, int rows, int columns);

	static void build_skybox();
}