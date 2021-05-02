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

		vertices.clear();
		normals.clear();
		uvs.clear();

		// load test geometry.
		loadOBJ("models/box.obj", vertices, uvs, normals);
		Geometry g2 = Geometry(vertices, uvs, normals);
		g2.load_texture("textures/Yellobrk.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("teapot", g2);


		SkyboxBottomGeometry skybox_bottom;
		skybox_bottom.load_texture("textures/skybox/bluecloud-dn.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("skybox_bottom", skybox_bottom);

		SkyboxTopGeometry skybox_top;
		skybox_top.load_texture("textures/skybox/bluecloud-up.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("skybox_top", skybox_top);

		SkyboxLeftGeometry skybox_left;
		skybox_left.load_texture("textures/skybox/bluecloud-lf.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("skybox_left", skybox_left);

		SkyboxRightGeometry skybox_right;
		skybox_right.load_texture("textures/skybox/bluecloud-rt.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("skybox_right", skybox_right);

		SkyboxFrontGeometry skybox_front;
		skybox_front.load_texture("textures/skybox/bluecloud-ft.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("skybox_front", skybox_front);

		SkyboxBackGeometry skybox_back;
		skybox_back.load_texture("textures/skybox/bluecloud-bk.bmp", TextureType::BMP);
		GeometryManager::get_instance()->add_geometry("skybox_back", skybox_back);

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