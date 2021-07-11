#pragma once

#include <glm/glm.hpp>

#include "environmentmanager.h"

#include "geometry.h"
#include "floortile_geometry.h"

#include "mesh.h"
#include "mesh_grouping.h"

namespace builders::environment {

	/**
	* Initialize the environment by placing things in it.
	*/
	void init();
	
	/**
	* Construct the floor using tiles.
	*
	* Different tiles are identified using different numbers.
	* 1 = grass tile
	* 2 = dirt tile
	* 3 = road tile
	*
	* @param tilemap the multidimensional array containing the identifiers.
	* @param rows the amount of arrays in the multidimensional array
	* @param columns the amount of values per array in the multidimensional array
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_floor(int tilemap[][32], int rows, int columns);

	/**
	* Create a skybox model for the given position.
	*
	* @return Mesh&
	*/
	static Mesh& build_skybox();

	/**
	* Create a house model for the given position.
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_house(glm::vec3 position);

	/**
	* Create a fence model for the given position.
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_fence(glm::vec3 position);

	/**
	* Create a tree model for the given position.
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_tree(glm::vec3 position);
	
	/**
	* Create a dead tree model for the given position.
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_dead_tree(glm::vec3 position);

	/**
	* Create a flower model for the given position.
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_flower(glm::vec3 position);

	/**
	* Create a stemmed bush model for the given position.
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_stemmed_bush(glm::vec3 position);
	
	/**
	* Create a fruit bush model for the given position.
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_fruit_bush(glm::vec3 position);
	
	/**
	* Create a bird model for the given position.
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_bird(glm::vec3 position);

	/**
	* Create a couch model for the given position.
	*
	* @return MeshingGroup&
	*/
	static MeshGrouping& build_couch(glm::vec3 position);

}