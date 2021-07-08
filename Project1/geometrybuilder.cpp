#include "geometrybuilder.h"

namespace builders::geometry {
	
	/**
	* Initialize the geometries to be used within the environment.
	*/
	void init()
	{
		// load geometries for the house
		load_house_geometries();
		
		// load geometries for the skybox
		load_skybox_geometries();

		// load geometries for the tile(s)
		load_tile_geometries();

		// load geometries for the fence
		load_fence_geometries();

		// load geometries for the tree(s).
		load_tree_geometries();

		// load geometries for the bush(es)
		load_bush_geometries();

		// load geometries for the flower(s)
		load_flower_geometries();

		// load geometries for the animal(s)
		load_animal_geometries();
	}

	void load_house_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load house roof geometry.
		loadOBJ("models/house/house_roof.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("house_roof", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load house block geometry
		loadOBJ("models/house/house_block.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/Yellobrk.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("house_block", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load house window geometry
		loadOBJ("models/house/house_window.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("house_window", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load house door geometry
		loadOBJ("models/house/house_door.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("house_door", geom);
	}

	void load_skybox_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		loadOBJ("models/skybox.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("skybox", geom);
	}

	void load_tile_geometries()
	{
		// Tile variant grass
		FloorTileGeometry floor_tile_type_A;
		floor_tile_type_A.load_texture("textures/tiles/tile_A.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("tile_A", floor_tile_type_A);

		// Tile variant dirt
		FloorTileGeometry floor_tile_type_B;
		floor_tile_type_B.load_texture("textures/tiles/tile_B.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("tile_B", floor_tile_type_B);
	}

	void load_fence_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;
		// models/fence/fence

		// load fence stone supports
		loadOBJ("models/fence/fence/stone_fence_supports.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("stone_fence_supports", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence supports
		loadOBJ("models/fence/fence/fence_supports.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fence_supports", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence planks
		loadOBJ("models/fence/fence/fence_planks.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fence_planks", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence plank tops
		loadOBJ("models/fence/fence/fence_plank_tops.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fence_plank_tops", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence plank supports
		loadOBJ("models/fence/fence/fence_plank_supports.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fence_plank_supports", geom);

	}

	void load_tree_geometries()
	{
	}

	void load_bush_geometries()
	{
	}

	void load_flower_geometries()
	{
	}

	void load_animal_geometries()
	{
	}

}