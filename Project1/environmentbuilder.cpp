#include "environmentbuilder.h"

#include <iostream>

namespace builders::environment {
	
	/**
	* Initialize the environment by placing things in it.
	*/
	void init()
	{

		// tilemap for the ground.
		int** tile_map = new int* [32];
		tile_map[0] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[1] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[2] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[3] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[4] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[5] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[6] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[7] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[8] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[9] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[10] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[11] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[12] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[13] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[14] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[15] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[16] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[17] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[18] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[19] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[20] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[21] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[22] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[23] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[24] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[25] = new int[32]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1 };
		tile_map[26] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[27] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[28] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[29] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[30] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		tile_map[31] = new int[32]{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };


		build_floor(tile_map, 32, 32);
		build_skybox();

		build_house(glm::vec3(10, 1, 10), glm::mat4());

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
	static void build_floor(int** tilemap, int rows, int columns)
	{
		MeshGrouping* grouping = new MeshGrouping();

		glm::vec3 midpoint = glm::vec3(rows / 2, 1.0, columns / 2);

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				glm::vec3 pos = glm::vec3(i * 2.0, 1.0, j * 2.0);
				// middle should be shiniest, from then on should become less shiny.
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

	void build_house(glm::vec3 position, glm::mat4 model) {
		MeshGrouping* grouping = new MeshGrouping();

		Mesh house_block = Mesh(GeometryManager::get_instance()->get_geometry("house_block"), position);
		Mesh house_roof = Mesh(GeometryManager::get_instance()->get_geometry("house_roof"), position);
		Mesh house_window = Mesh(GeometryManager::get_instance()->get_geometry("house_window"), position);
		Mesh house_door = Mesh(GeometryManager::get_instance()->get_geometry("house_door"), position);

		grouping->add(house_block);
		grouping->add(house_roof);
		grouping->add(house_window);
		grouping->add(house_door);

		EnvironmentManager::get_instance()->add(grouping);
	}

}