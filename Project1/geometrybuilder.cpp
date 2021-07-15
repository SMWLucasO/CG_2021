#include "geometrybuilder.h"

namespace builders::geometry {
	
	void init()
	{
		// load geometries for the house
		load_house_geometries();

		// load geometries for the house veranda.
		load_house_veranda_geometries();
		
		// load geometries for the skybox
		load_skybox_geometries();

		// load geometries for the tile(s)
		load_tile_geometries();

		// load geometries for the fence
		load_fence_geometries();

		// load geometries for the fence gate
		load_fence_gate_geometries();

		// load geometries for the tree(s).
		load_tree_geometries();

		// load geometries for the bush(es)
		load_bush_geometries();

		// load geometries for the flower(s)
		load_flower_geometries();

		// load geometries for the animal(s)
		load_animal_geometries();

		// load geometries for furniture
		load_furniture_geometries();
	}

	void load_house_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load house roof geometry.
		loadOBJ("models/house/house_roof.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/gray.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("house_roof", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load house walls geometry
		loadOBJ("models/house/house_walls.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/house/wall.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("house_block", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load house windows geometry
		loadOBJ("models/house/house_windows.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/window_blue.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("house_window", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load house door geometry
		loadOBJ("models/house/house_door.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/brown.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("house_door", geom);
	}

	void load_house_veranda_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load house veranda floor geometry.
		loadOBJ("models/house/veranda/veranda_floor.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/house/veranda/veranda_floor.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("veranda_floor", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load veranda poles geometry
		loadOBJ("models/house/veranda/veranda_poles.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/brown.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("veranda_poles", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load veranda roof geometry
		loadOBJ("models/house/veranda/veranda_roof.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/house/veranda/veranda_roof.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("veranda_roof", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load veranda stairs geometry
		loadOBJ("models/house/veranda/veranda_stairs.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/gray.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("veranda_stairs", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load veranda supports geometry
		loadOBJ("models/house/veranda/veranda_supports.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/gray.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("veranda_supports", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load house door geometry
		loadOBJ("models/house/veranda/veranda_walls.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/house/veranda/veranda_wall.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("veranda_walls", geom);
	}

	void load_skybox_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load the skybox geometry.
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

		// Tile variant road
		FloorTileGeometry floor_tile_type_C;
		floor_tile_type_C.load_texture("textures/tiles/tile_C.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("tile_C", floor_tile_type_C);
	}


	void load_fence_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load fence stone supports
		loadOBJ("models/fence/fence/stone_fence_supports.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/fence/seamless-granite.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("stone_fence_supports", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence supports
		loadOBJ("models/fence/fence/fence_supports.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/fence/seamless-wood.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fence_supports", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence planks
		loadOBJ("models/fence/fence/fence_planks.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/fence/seamless-wood.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fence_planks", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence plank tops
		loadOBJ("models/fence/fence/fence_plank_tops.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/fence/seamless-wood.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fence_plank_tops", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence plank supports
		loadOBJ("models/fence/fence/fence_plank_supports.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/fence/seamless-wood.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fence_plank_supports", geom);

	}

	void load_fence_gate_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;
		// models/fence/fence

		// load fence stone supports
		loadOBJ("models/fence/gate/fencegate_garnier.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fencegate_garnier", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence supports
		loadOBJ("models/fence/gate/fencegate_gatehandle.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fencegate_gatehandle", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence planks
		loadOBJ("models/fence/gate/fencegate_gateplank.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fencegate_gateplank", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load fence plank tops
		loadOBJ("models/fence/gate/fencegate_gatesupports.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("fencegate_gatesupports", geom);
	}

	void load_tree_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load dead tree.
		loadOBJ("models/trees/deadtree/deadtree.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/brown.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("dead_tree", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load regular tree leafs
		loadOBJ("models/trees/tree/tree_leafs.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/trees/leafs.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("tree_leafs", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load regular tree stem
		loadOBJ("models/trees/tree/tree_stem.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/brown.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("tree_stem", geom);
	}

	void load_bush_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load regular bush's bush
		loadOBJ("models/bushes/bush/bush_bush.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/bushes/bush.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("regular_bush_bush", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load regular bush's fruits
		loadOBJ("models/bushes/bush/bush_fruits.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/red.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("regular_bush_fruits", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load stemmed bush bush
		loadOBJ("models/bushes/bushwithstem/bush_bush.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/bushes/bush.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("stemmed_bush_bush", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load stemmed bush stem
		loadOBJ("models/bushes/bushwithstem/bush_stem.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/brown.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("stemmed_bush_stem", geom);

	}

	void load_flower_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load flower stem
		loadOBJ("models/flower/flower_stem.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("flower_stem", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load flower leafs
		loadOBJ("models/flower/flower_leafs.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/flower/sunflower.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("flower_leafs", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load inner part of flower (where the seeds n stuff would be)
		loadOBJ("models/flower/flower_inner.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/flower/sunflower.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("flower_inner", geom);
	}

	void load_animal_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load bird body
		loadOBJ("models/animals/bird/bird_body.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("bird_body", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load left wing of bird
		loadOBJ("models/animals/bird/bird_left_wing.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("bird_left_wing", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load right wing of bird
		loadOBJ("models/animals/bird/bird_right_wing.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		//geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("bird_right_wing", geom);
	}

	void load_furniture_geometries()
	{
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;

		// load the couch
		loadOBJ("models/furniture/couch/couch_couch.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/furniture/seamless-sofa-texture.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("couch_couch", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load the seats of the couch
		loadOBJ("models/furniture/couch/couch_seat.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/furniture/seamless-sofa-texture.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("couch_seat", geom);
	}

}