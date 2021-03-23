#include "geometryloader.h"

GeometryLoader* GeometryLoader::instance{ nullptr };

GeometryLoader::GeometryLoader()
{
}

GeometryLoader::~GeometryLoader()
{
	delete instance;
}


/**
 * <description>
 *
 * @param
 * @return
*/
void GeometryLoader::load_geometry(GeometryManager& geom_manager, std::string path)
{
	rapidjson::Document document = JsonLoader::get_instance()->load_json_from_file(path);

	assert(document.IsObj());
	assert(document.HasMember("geometries"));

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;

	for (rapidjson::Value::ConstValueIterator it = document["geometries"].Begin(); it != document["geometries"].End(); ++it)
	{
		json_object object = it->GetObj();

		if (!(object.HasMember("obj_file_location") || object.HasMember("name"))) continue; // !(a v b) == !a ^ !b

		// load the normals, vertices and UVs for the object.
		loadOBJ(object["obj_file_location"].GetString(), vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);

		// load the texture for the geometry if there is one.
		if (object.HasMember("texture")) {
			assert(object["texture"].IsObj());

			json_object texture_obj = object["texture"].GetObj();

			// these two members must exist if we want to use textures.
			assert(texture_obj.HasMember("url"));
			assert(texture_obj.HasMember("type"));
			assert(texture_obj["url"].IsString());
			assert(texture_obj["type"].IsString());

			// dds is a special case, bmp is the default. Thus, we apply bmp by default.
			TextureType texture_type = TextureType::BMP;
			if (texture_obj["type"].GetString() == "dds")
				texture_type = TextureType::DDS;

			geom.load_texture(texture_obj["url"].GetString(), texture_type);
		}

		geom_manager.add_geometry(object["name"].GetString(), geom);
	}
}

/**
 * Get the instance of the singleton environment loader.
 *
 * @return A pointer to the EnvironmentLoader singleton
*/
GeometryLoader* GeometryLoader::get_instance()
{

	if (GeometryLoader::instance == nullptr) {
		instance = new GeometryLoader();
	}

	return GeometryLoader::instance;
}