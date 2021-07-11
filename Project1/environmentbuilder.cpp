#include "environmentbuilder.h"

#include <iostream>

namespace builders::environment {
	
	void init()
	{

		// tilemap for the ground.
		int tile_map[][32] = {
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
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
		MeshGrouping& stemmed_bush_1 = build_stemmed_bush(glm::vec3(12.6, 0, 12.8));
		stemmed_bush_1.set_rotations(glm::vec3(0, 315, 0));

		MeshGrouping& stemmed_bush_2 = build_stemmed_bush(glm::vec3(19.8, 0, 12.8));
		stemmed_bush_2.set_rotations(glm::vec3(0, 45, 0));

		for (int i = 0; i < 27; i++)
			if (i % 4 == 0) // place a fruit bush every 4 steps.
			{
				build_fruit_bush(glm::vec3(19.3, .1, 29 + i));
				
				// place an additional fruit bush on the right of it when i > 6 (looks good, that's the only reason.)
				if (i > 6)
					build_fruit_bush(glm::vec3(12.8, .1, 29 + i));
			}
		

	}

	MeshGrouping& build_floor(int tilemap[][32], int rows, int columns)
	{
		MeshGrouping* grouping = new MeshGrouping();

		glm::vec3 midpoint = glm::vec3(rows, 0, columns);

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				glm::vec3 pos = glm::vec3(i * 2.0, 0, j * 2.0);
				
				// calculate the shininess of the floor tile based upon our midpoint and the given position.
				int shininess = 32 + 32 * glm::distance(midpoint, pos);  
				if (tilemap[i][j] == 1)
				{
					Mesh m = Mesh(GeometryManager::get_instance()->get_geometry("tile_A"), pos);
					m.set_shader_type(ShaderType::Phong);
					m.set_material_power(shininess);
					grouping->add(m);
				}
				else if (tilemap[i][j] == 2)
				{
					Mesh m = Mesh(GeometryManager::get_instance()->get_geometry("tile_B"), pos);
					m.set_shader_type(ShaderType::Phong);
					m.set_material_power(shininess);
					grouping->add(m);
				}
				else
				{
					Mesh m = Mesh(GeometryManager::get_instance()->get_geometry("tile_C"), pos);
					m.set_shader_type(ShaderType::Phong);
					m.set_material_power(shininess);
					grouping->add(m);
				}
			}
		}

		// add the floor to the world environment.
		EnvironmentManager::get_instance()->add(grouping);
		return *grouping;
	}

	Mesh& build_skybox()
	{
		// get the skybox geometry and make a new mesh from it.
		Geometry* skybox = GeometryManager::get_instance()->get_geometry("skybox");
		Mesh* skybox_entity = new Mesh(skybox, glm::vec3(0, 0, 0));

		// set the shader type and size of the skybox
		skybox_entity->set_shader_type(ShaderType::Basic);
		skybox_entity->set_scaling(glm::vec3(800, 800, 800));

		// set up the skybox
		skybox_entity->set_texture_enabled(true);
		skybox_entity->setup();

		// add the skybox to the world.
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

		// add the fencegate to the grouping.
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
		// Create a new mesh grouping and add the tree_leafs / tree_stem meshes to it.
		MeshGrouping* grouping = new MeshGrouping();

		Mesh tree_leafs = Mesh(GeometryManager::get_instance()->get_geometry("tree_leafs"), glm::vec3(0, 0, 0));
		Mesh tree_stem = Mesh(GeometryManager::get_instance()->get_geometry("tree_stem"), glm::vec3(0, 0, 0));

		grouping->add(tree_leafs);
		grouping->add(tree_stem);

		// set the position of the grouping to the given one.
		grouping->set_position(position);

		// set it up & add it to the world.
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_dead_tree(glm::vec3 position)
	{
		// create a mesh grouping & add the dead_tree mesh to it.
		MeshGrouping* grouping = new MeshGrouping();

		Mesh dead_tree = Mesh(GeometryManager::get_instance()->get_geometry("dead_tree"), glm::vec3(0, 0, 0));
		
		grouping->add(dead_tree);

		// set the position for the grouping
		grouping->set_position(position);

		// setup & add to the world.
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_flower(glm::vec3 position)
	{
		// create a grouping for the meshes.
		MeshGrouping* grouping = new MeshGrouping();
		
		// create the meshes for the flower.
		Mesh flower_stem = Mesh(GeometryManager::get_instance()->get_geometry("flower_stem"), glm::vec3(0, 0, 0));
		Mesh flower_leafs = Mesh(GeometryManager::get_instance()->get_geometry("flower_leafs"), glm::vec3(0, 0, 0));
		Mesh flower_inner = Mesh(GeometryManager::get_instance()->get_geometry("flower_inner"), glm::vec3(0, 0, 0));

		// add the pieces to the grouping.
		grouping->add(flower_stem);
		grouping->add(flower_leafs);
		grouping->add(flower_inner);

		// set the position of the flower
		grouping->set_position(position);

		// setup & add to the world.
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_stemmed_bush(glm::vec3 position)
	{
		// Create a grouping for the stemmed bush.
		MeshGrouping* grouping = new MeshGrouping();

		// Create the meshes that the stemmed bush consists of.
		Mesh stemmed_bush_bush = Mesh(GeometryManager::get_instance()->get_geometry("stemmed_bush_bush"), glm::vec3(0, 0, 0));
		Mesh stemmed_bush_stem = Mesh(GeometryManager::get_instance()->get_geometry("stemmed_bush_stem"), glm::vec3(0, 0, 0));

		// add the meshes to the grouping & set the position of the grouping to the correct location.
		grouping->add(stemmed_bush_bush);
		grouping->add(stemmed_bush_stem);

		grouping->set_position(position);

		// set up the grouping & add it to the world.
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}
	
	MeshGrouping& build_fruit_bush(glm::vec3 position)
	{
		// Create a grouping for the fruit bush
		MeshGrouping* grouping = new MeshGrouping();

		// Create the meshes that the fruit bush consists of.
		Mesh regular_bush_bush = Mesh(GeometryManager::get_instance()->get_geometry("regular_bush_bush"), glm::vec3(0, 0, 0));
		Mesh regular_bush_fruits = Mesh(GeometryManager::get_instance()->get_geometry("regular_bush_fruits"), glm::vec3(0, 0, 0));

		// Add the meshes to the mesh grouping & set the position.
		grouping->add(regular_bush_bush);
		grouping->add(regular_bush_fruits);

		grouping->set_position(position);

		// set up the grouping & add it to the world.
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_bird(glm::vec3 position)
	{
		// Create a grouping for the bird.
		MeshGrouping* grouping = new MeshGrouping();

		// Create the meshes of which the bird consists of.
		Mesh bird_body = Mesh(GeometryManager::get_instance()->get_geometry("bird_body"), glm::vec3(0, 0, 0));
		Mesh bird_left_wing = Mesh(GeometryManager::get_instance()->get_geometry("bird_left_wing"), glm::vec3(0, 0, 0));
		Mesh bird_right_wing = Mesh(GeometryManager::get_instance()->get_geometry("bird_right_wing"), glm::vec3(0, 0, 0));

		// Add the meshes to the grouping & set the position of the grouping.
		grouping->add(bird_body);
		grouping->add(bird_left_wing);
		grouping->add(bird_right_wing);

		grouping->set_position(position);

		// set up the grouping & add it to the world.
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

	MeshGrouping& build_couch(glm::vec3 position)
	{
		// Create a grouping for the couch
		MeshGrouping* grouping = new MeshGrouping();

		// Create the meshes of which the couch meshgrouping consists.
		Mesh couch_couch = Mesh(GeometryManager::get_instance()->get_geometry("couch_couch"), glm::vec3(0, 0, 0));
		Mesh couch_seats = Mesh(GeometryManager::get_instance()->get_geometry("couch_seats"), glm::vec3(0, 0, 0));

		// Set the material power of the couch for better shininess.
		couch_couch.set_material_power(32);
		couch_seats.set_material_power(32);

		// Add the meshes to the grouping & set the position of the grouping
		grouping->add(couch_couch);
		grouping->add(couch_seats);

		grouping->set_position(position);

		// set up the grouping & add it to the world.
		grouping->setup();
		EnvironmentManager::get_instance()->add(grouping);

		return *grouping;
	}

}