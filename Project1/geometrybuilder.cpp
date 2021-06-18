#include "geometrybuilder.h"

namespace builders::geometry {
	
	/**
	* Initialize the geometries to be used within the environment.
	*/
	void init()
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

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load skybox geometry
		loadOBJ("models/skybox.obj", vertices, uvs, normals);
		geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("skybox", geom);

		vertices.clear();
		normals.clear();
		uvs.clear();

		// Tile variant grass
		FloorTileGeometry floor_tile_type_A;
		floor_tile_type_A.load_texture("textures/tiles/tile_A.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("tile_A", floor_tile_type_A);

		// Tile variant dirt
		FloorTileGeometry floor_tile_type_B;
		floor_tile_type_B.load_texture("textures/tiles/tile_B.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("tile_B", floor_tile_type_B);

	}

}