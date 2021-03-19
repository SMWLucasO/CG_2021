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

		loadOBJ(object["obj_file_location"].GetString(), vertices, uvs, normals);
		Geometry geom = Geometry(vertices, uvs, normals);

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