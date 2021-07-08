#include "environmentbuilder.h"

#include <iostream>

namespace builders::environment {
	
	/**
	* Initialize the environment by placing things in it.
	*/
	void init()
	{

		// tilemap for the ground.
		int tile_map[][32] = {
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		};


		build_floor(tile_map, 12, 32);

		build_skybox();

		build_house(glm::vec3(5, 3, 25));
		
		build_fence(glm::vec3(18, 0.4, 10.4));
	}

	/**
	* Construct the floor using tiles.
	* 
	* Different tiles are identified using different numbers.
	* 1 = grass tile
	* 2 = dirt tile
	* 
	* @param tilemap the multidimensional array containing the identifiers.
	* @param rows the amount of arrays in the multidimensional array
	* @param columns the amount of values per array in the multidimensional array
	*/
	static void build_floor(int tilemap[][32], int rows, int columns)
	{
		MeshGrouping* grouping = new MeshGrouping();

		glm::vec3 midpoint = glm::vec3(rows / 2, 1.0, columns / 2);

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				glm::vec3 pos = glm::vec3(i* 2.0, 0, j * 2.0);
				// middle should be shiniest, from then on should become less shiny.
				// TODO fix this so that it works (shininess is at its peak at th wrong point)
				int shininess = 32 + 32 * glm::distance(midpoint, pos);  // apply Euclid distance with minimum shininess.
				if (tilemap[i][j] == 1) {
					Mesh m = Mesh(GeometryManager::get_instance()->get_geometry("tile_A"), pos);
					m.set_material_power(shininess);
					grouping->add(m);
				}
				else
				{
					Mesh m = Mesh(GeometryManager::get_instance()->get_geometry("tile_B"), pos);
					m.set_material_power(shininess);
					grouping->add(m);
				}
			}
		}

		EnvironmentManager::get_instance()->add(grouping);
	}

	void build_skybox()
	{
		Geometry* skybox = GeometryManager::get_instance()->get_geometry("skybox");
		Mesh* skybox_entity = new Mesh(skybox, glm::vec3(0, 0, 0));

		skybox_entity->set_shader_type(ShaderType::Basic);
		skybox_entity->set_scaling(glm::vec3(800, 800, 800));

		skybox_entity->set_texture_enabled(true);
		skybox_entity->setup();

		EnvironmentManager::get_instance()->add(skybox_entity);
	}

	void build_house(glm::vec3 position) {
		
		/// create a grouping for the house
		MeshGrouping* grouping = new MeshGrouping();

		// create the house meshes
		Mesh house_block = Mesh(GeometryManager::get_instance()->get_geometry("house_block"), glm::vec3(0, 0, 0));
		Mesh house_roof = Mesh(GeometryManager::get_instance()->get_geometry("house_roof"), glm::vec3(0, 0, 0));
		Mesh house_window = Mesh(GeometryManager::get_instance()->get_geometry("house_window"), glm::vec3(0, 0, 0));
		Mesh house_door = Mesh(GeometryManager::get_instance()->get_geometry("house_door"), glm::vec3(0,0,0));

		// set the shaders for the house
		house_block.set_shader_type(ShaderType::Basic);
		house_roof.set_shader_type(ShaderType::Basic);
		house_window.set_shader_type(ShaderType::Basic);
		house_door.set_shader_type(ShaderType::Basic);

		// add everything to the grouping
		grouping->add(house_block);
		grouping->add(house_roof);
		grouping->add(house_window);
		grouping->add(house_door);

		// set any transformations
		grouping->set_position(position);
		grouping->set_rotations(glm::vec3(0, 110, 0));

		// setup n stuff
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);
	}

	void build_fence(glm::vec3 position)
	{
		/// create a grouping for the fence
		MeshGrouping* grouping = new MeshGrouping();

		// create the fence meshes
		Mesh stone_fence_supports = Mesh(GeometryManager::get_instance()->get_geometry("stone_fence_supports"), glm::vec3(0,0,0));
		Mesh fence_supports = Mesh(GeometryManager::get_instance()->get_geometry("fence_supports"), glm::vec3(0, 0, 0));
		Mesh fence_planks = Mesh(GeometryManager::get_instance()->get_geometry("fence_planks"), glm::vec3(0, 0, 0));
		Mesh fence_plank_tops = Mesh(GeometryManager::get_instance()->get_geometry("fence_plank_tops"), glm::vec3(0, 0, 0));
		Mesh fence_plank_supports = Mesh(GeometryManager::get_instance()->get_geometry("fence_plank_supports"), glm::vec3(0, 0, 0));

		// set the shaders for the fence
		stone_fence_supports.set_shader_type(ShaderType::Phong);
		fence_supports.set_shader_type(ShaderType::Phong);
		fence_planks.set_shader_type(ShaderType::Phong);
		fence_plank_tops.set_shader_type(ShaderType::Phong);
		fence_plank_supports.set_shader_type(ShaderType::Phong);

		// add everything to the grouping
		grouping->add(stone_fence_supports);
		grouping->add(fence_supports);
		grouping->add(fence_planks);
		grouping->add(fence_plank_tops);
		grouping->add(fence_plank_supports);

		// set any transformations
		grouping->set_position(position);
		//grouping->set_rotations(glm::vec3(0, 45, 0));

		// setup n stuff
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);
	}

}