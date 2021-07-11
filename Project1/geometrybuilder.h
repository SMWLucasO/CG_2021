#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "geometry.h"
#include "geometrymanager.h"

#include "floortile_geometry.h"

#include "loaders/object/objloader.h"

namespace builders::geometry {
	
	/**
	* Initialize the geometries to be used within the environment.
	*/
	void init();

	/**
	* Load the geometries for the house.
	*/
	static void load_house_geometries();

	/**
	* Load the geometries for the skybox.
	*/
	static void load_skybox_geometries();

	/**
	* Load the geometries for the different types of (ground) tiles.
	*/
	static void load_tile_geometries();

	/**
	* Load the geometries for the fence.
	*/
	static void load_fence_geometries();

	/**
	* Load the geometries for the fence gate.
	*/
	static void load_fence_gate_geometries();

	/**
	* Load the geometries for the trees.
	*/
	static void load_tree_geometries();

	/**
	* Load the geometries for bushes.
	*/
	static void load_bush_geometries();

	/**
	* Load the geometries for the flower.
	*/
	static void load_flower_geometries();

	/**
	* Load the geometries for the animals.
	*/
	static void load_animal_geometries();

	/**
	* Load the geometries for the furniture.
	*/
	static void load_furniture_geometries();

}