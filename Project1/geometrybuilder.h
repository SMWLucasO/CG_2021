#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "geometry.h"
#include "geometrymanager.h"

#include "floortile_geometry.h"

#include "loaders/object/objloader.h"

namespace builders::geometry {
	
	void init();

	static void load_house_geometries();

	static void load_skybox_geometries();

	static void load_tile_geometries();

	static void load_fence_geometries();

	static void load_tree_geometries();

	static void load_bush_geometries();

	static void load_flower_geometries();

	static void load_animal_geometries();

}