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


		// setup the floor.
		build_floor(tile_map, 12, 32);

		// setup the skybox.
		build_skybox();

		// setup the house
		MeshGrouping& house = build_house(glm::vec3(5, 3, 25));
		house.set_rotations(glm::vec3(0, 110, 0));

		// setup couches
		MeshGrouping& house_couch = build_couch(glm::vec3(7, 0, 29.1));
		house_couch.set_rotations(glm::vec3(0, 290, 0));

		MeshGrouping& fence_couch = build_couch(glm::vec3(19, 0, 16));
		fence_couch.set_rotations(glm::vec3(0, 100, 0));

		// setup the fence
		build_fence(glm::vec3(18, 0.4, 10.4));

		// setup the trees
		build_dead_tree(glm::vec3(16, .9f, 9.7f));
		build_tree(glm::vec3(20, .9f, 60));

		// setup birds
		build_bird(glm::vec3(16, 15, 8.8));
		build_bird(glm::vec3(14, 15, 6.8));
		build_bird(glm::vec3(12, 15, 8.8));

		build_bird(glm::vec3(10, 15, 32));
		build_bird(glm::vec3(8, 15, 30));
		build_bird(glm::vec3(6, 15, 28));

		// add some flowers
		for (int i = 0; i < 10; i++)
			if (i != 4 && i != 5 && i != 6)
				build_flower(glm::vec3(11.3 + i, 0, 31 - i));

		// add some bushes
		MeshGrouping& st_bush_1 = build_stemmed_bush(glm::vec3(12.6, 0, 12.8));
		st_bush_1.set_rotations(glm::vec3(0, 315, 0));

		MeshGrouping& st_bush_2 = build_stemmed_bush(glm::vec3(19.8, 0, 12.8));
		st_bush_2.set_rotations(glm::vec3(0, 45, 0));

		for (int i = 0; i < 27; i++)
			if (i % 4 == 0)
			{
				build_fruit_bush(glm::vec3(19.3, .1, 29 + i));

				if (i > 6)
					build_fruit_bush(glm::vec3(12.8, .1, 29 + i));
			}
		

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
	MeshGrouping& build_floor(int tilemap[][32], int rows, int columns)
	{
		MeshGrouping* grouping = new MeshGrouping();

		glm::vec3 midpoint = glm::vec3(rows / 2, 1.0, columns / 2);

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				glm::vec3 pos = glm::vec3(i* 2.0, 0, j * 2.0);
				// middle should be shiniest, from then on should become less shiny.
				// TODO fix this so that it works (shininess is at its peak at th wrong point)
				int shininess = 32 + 32 * glm::distance(midpoint, pos);  // apply Euclid distance with minimum shininess.
				if (tilemap[i][j] == 1)
				{
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
		return *grouping;
	}

	Mesh& build_skybox()
	{
		Geometry* skybox = GeometryManager::get_instance()->get_geometry("skybox");
		Mesh* skybox_entity = new Mesh(skybox, glm::vec3(0, 0, 0));

		skybox_entity->set_shader_type(ShaderType::Basic);
		skybox_entity->set_scaling(glm::vec3(800, 800, 800));

		skybox_entity->set_texture_enabled(true);
		skybox_entity->setup();

		EnvironmentManager::get_instance()->add(skybox_entity);

		return *skybox_entity;
	}

	MeshGrouping& build_house(glm::vec3 position) {
		
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

		// setup n stuff
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_fence(glm::vec3 position)
	{
		/// create a grouping for the fence
		MeshGrouping* grouping = new MeshGrouping();

		// create the fence meshes
		Mesh stone_fence_supports = Mesh(GeometryManager::get_instance()->get_geometry("stone_fence_supports"), glm::vec3(0,0,0));
		Mesh fence_supports = Mesh(GeometryManager::get_instance()->get_geometry("fence_supports"), glm::vec3(0, 0, 0));
		Mesh fence_planks = Mesh(GeometryManager::get_instance()->get_geometry("fence_planks"), glm::vec3(0, 0, 0));
		Mesh fence_plank_tops = Mesh(GeometryManager::get_instance()->get_geometry("fence_plank_tops"), glm::vec3(0, 0, 0));
		Mesh fence_plank_supports = Mesh(GeometryManager::get_instance()->get_geometry("fence_plank_supports"), glm::vec3(0, 0, 0));

		// add everything to the grouping
		grouping->add(stone_fence_supports);
		grouping->add(fence_supports);
		grouping->add(fence_planks);
		grouping->add(fence_plank_tops);
		grouping->add(fence_plank_supports);

		// create fence gate meshes
		Mesh fencegate_garnier = Mesh(GeometryManager::get_instance()->get_geometry("fencegate_garnier"), glm::vec3(0, 0, 0));
		Mesh fencegate_gatehandle = Mesh(GeometryManager::get_instance()->get_geometry("fencegate_gatehandle"), glm::vec3(0, 0, 0));
		Mesh fencegate_gateplank = Mesh(GeometryManager::get_instance()->get_geometry("fencegate_gateplank"), glm::vec3(0, 0, 0));
		Mesh fencegate_gatesupports = Mesh(GeometryManager::get_instance()->get_geometry("fencegate_gatesupports"), glm::vec3(0, 0, 0));

		grouping->add(fencegate_garnier);
		grouping->add(fencegate_gatehandle);
		grouping->add(fencegate_gateplank);
		grouping->add(fencegate_gatesupports);

		// set any transformations
		grouping->set_position(position);

		// setup n stuff
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_tree(glm::vec3 position)
	{
		MeshGrouping* grouping = new MeshGrouping();

		Mesh tree_leafs = Mesh(GeometryManager::get_instance()->get_geometry("tree_leafs"), glm::vec3(0, 0, 0));
		Mesh tree_stem = Mesh(GeometryManager::get_instance()->get_geometry("tree_stem"), glm::vec3(0, 0, 0));

		grouping->add(tree_leafs);
		grouping->add(tree_stem);

		grouping->set_position(position);

		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_dead_tree(glm::vec3 position)
	{
		MeshGrouping* grouping = new MeshGrouping();

		Mesh dead_tree = Mesh(GeometryManager::get_instance()->get_geometry("dead_tree"), glm::vec3(0, 0, 0));
		
		grouping->add(dead_tree);

		grouping->set_position(position);

		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_flower(glm::vec3 position)
	{
		MeshGrouping* grouping = new MeshGrouping();
		
		Mesh flower_stem = Mesh(GeometryManager::get_instance()->get_geometry("flower_stem"), glm::vec3(0, 0, 0));
		Mesh flower_leafs = Mesh(GeometryManager::get_instance()->get_geometry("flower_leafs"), glm::vec3(0, 0, 0));
		Mesh flower_inner = Mesh(GeometryManager::get_instance()->get_geometry("flower_inner"), glm::vec3(0, 0, 0));

		grouping->add(flower_stem);
		grouping->add(flower_leafs);
		grouping->add(flower_inner);

		grouping->set_position(position);

		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_stemmed_bush(glm::vec3 position)
	{
		MeshGrouping* grouping = new MeshGrouping();

		Mesh stemmed_bush_bush = Mesh(GeometryManager::get_instance()->get_geometry("stemmed_bush_bush"), glm::vec3(0, 0, 0));
		Mesh stemmed_bush_stem = Mesh(GeometryManager::get_instance()->get_geometry("stemmed_bush_stem"), glm::vec3(0, 0, 0));

		grouping->add(stemmed_bush_bush);
		grouping->add(stemmed_bush_stem);

		grouping->set_position(position);

		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_fruit_bush(glm::vec3 position)
	{
		MeshGrouping* grouping = new MeshGrouping();

		Mesh regular_bush_bush = Mesh(GeometryManager::get_instance()->get_geometry("regular_bush_bush"), glm::vec3(0, 0, 0));
		Mesh regular_bush_fruits = Mesh(GeometryManager::get_instance()->get_geometry("regular_bush_fruits"), glm::vec3(0, 0, 0));

		grouping->add(regular_bush_bush);
		grouping->add(regular_bush_fruits);

		grouping->set_position(position);

		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_bird(glm::vec3 position)
	{
		MeshGrouping* grouping = new MeshGrouping();

		Mesh bird_body = Mesh(GeometryManager::get_instance()->get_geometry("bird_body"), glm::vec3(0, 0, 0));
		Mesh bird_left_wing = Mesh(GeometryManager::get_instance()->get_geometry("bird_left_wing"), glm::vec3(0, 0, 0));
		Mesh bird_right_wing = Mesh(GeometryManager::get_instance()->get_geometry("bird_right_wing"), glm::vec3(0, 0, 0));

		grouping->add(bird_body);
		grouping->add(bird_left_wing);
		grouping->add(bird_right_wing);

		grouping->set_position(position);

		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_couch(glm::vec3 position)
	{
		MeshGrouping* grouping = new MeshGrouping();

		Mesh couch_couch = Mesh(GeometryManager::get_instance()->get_geometry("couch_couch"), glm::vec3(0, 0, 0));
		Mesh couch_seats = Mesh(GeometryManager::get_instance()->get_geometry("couch_seats"), glm::vec3(0, 0, 0));

		grouping->add(couch_couch);
		grouping->add(couch_seats);

		grouping->set_position(position);

		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

}