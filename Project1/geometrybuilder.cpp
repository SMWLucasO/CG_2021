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

		// load skybox geometry.
		loadOBJ("models/skybox.obj", vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);
		geom.load_texture("textures/skybox/skybox.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("skybox", geom);

		// Tile variant 
		FloorTileGeometry floor_tile_type_A;
		floor_tile_type_A.load_texture("textures/tiles/tile_A.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("tile_A", floor_tile_type_A);

		// testing subclass
		FloorTileGeometry floor_tile_type_B;
		floor_tile_type_B.load_texture("textures/tiles/tile_B.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("tile_B", floor_tile_type_B);

	}

}