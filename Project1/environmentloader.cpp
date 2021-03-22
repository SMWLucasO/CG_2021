#include "environmentloader.h"

EnvironmentLoader* EnvironmentLoader::instance{ nullptr };

EnvironmentLoader::EnvironmentLoader()
{
}

EnvironmentLoader::~EnvironmentLoader()
{
	delete instance;
}

/**
* Load all objects into the environment.
*
* @param env_manager - EnvironmentManager& containing our environment
* @param path - the path to the json file (incl. the filename + extension).
*/
void EnvironmentLoader::load_environment(EnvironmentManager& env_manager, std::string path)
{
	
		rapidjson::Document document = JsonLoader::get_instance()->load_json_from_file(path); // todo loop through each file in folder.

		assert(document.IsObj());
		assert(document.HasMember("geomtype"));
		assert(document.HasMember("shader"));
		assert(document.HasMember("data_points"));
		assert(document["data_points"].IsArray());

		std::string geom_type = document["geomtype"].GetString();
		std::string shader_name = document["shader"].GetString();

		Geometry* geom = GeometryManager::get_instance()->get_geometry(geom_type);
		ShaderType shader_type = ShadingManager::get_instance()->get_shader_type_from_string(shader_name);

		for (rapidjson::Value::ConstValueIterator it = document["data_points"].Begin(); it != document["data_points"].End(); ++it)
		{
			// pos, geom, transf.
			json_object object = it->GetObj();

			assert(object.HasMember("position"));
			assert(object["position"].IsObj());
			assert(object.HasMember("rotation"));
			assert(object["rotation"].IsObj());
			assert(object.HasMember("sizes"));
			assert(object["sizes"].IsObj());

			// we have to use pointers, we are making use of a pure-virtual Entity abstract class.
			EnvironmentEntity* entity = new EnvironmentEntity(geom, this->get_position(object["position"].GetObj()), this->get_transformations(object));

			// material changes are optional
			if (object.HasMember("material_data")) {
				entity->set_material(this->get_material(entity->get_material(), object["material_data"].GetObj()));
			}

			env_manager.add(entity);
		}	
}

/**
* Get all transformation data from the json object.
*
* @param json json object containing the previously mentioned data.
* @return Transformations containing the optionally defined data.
*/
Transformations EnvironmentLoader::get_transformations(json_object json)
{
	Transformations transforms;

	assert(json["rotation"].HasMember("x"));
	assert(json["rotation"].HasMember("y"));
	assert(json["rotation"].HasMember("z"));

	assert(json["rotation"]["x"].IsNumber());
	assert(json["rotation"]["y"].IsNumber());
	assert(json["rotation"]["z"].IsNumber());

	assert(json["sizes"].HasMember("width"));
	assert(json["sizes"].HasMember("height"));
	assert(json["sizes"].HasMember("depth"));
	
	assert(json["sizes"]["width"].IsNumber());
	assert(json["sizes"]["height"].IsNumber());
	assert(json["sizes"]["depth"].IsNumber());

	transforms.rotations = glm::vec3(json["rotation"]["x"].GetFloat(), json["rotation"]["y"].GetFloat(), json["rotation"]["z"].GetFloat());
	transforms.scaling = glm::vec3(json["sizes"]["width"].GetFloat(), json["sizes"]["height"].GetFloat(), json["sizes"]["depth"].GetFloat());

	return transforms;
}

/**
* Get all material data from the json object.
*
* @param json json object containing the previously mentioned data.
* @return Material containing the optionally defined data.
*/
Material EnvironmentLoader::get_material(Material initial_material, json_object json)
{
	Material material;

	// within the material data, each data point is optional.
	// possible points: power, specular, diffuse_color and ambient_color.

	if (json.HasMember("power")) {
		assert(json["power"].IsNumber());

		material.power = json["power"].GetFloat();
	}

	if (json.HasMember("specular")) {
		assert(json["specular"].IsObj());

		assert(json["specular"].HasMember("x"));
		assert(json["specular"].HasMember("y"));
		assert(json["specular"].HasMember("z"));

		assert(json["specular"]["x"].IsNumber());
		assert(json["specular"]["y"].IsNumber());
		assert(json["specular"]["z"].IsNumber());

		material.specular = glm::vec3(json["specular"]["x"].GetFloat(), json["specular"]["y"].GetFloat(), json["specular"]["z"].GetFloat());
	}

	if (json.HasMember("diffuse_color")) {
		assert(json["diffuse_color"].IsObj());

		material.diffuse_color = this->get_color(json["diffuse_color"].GetObj());
	}

	if (json.HasMember("ambient_color")) {
		assert(json["ambient_color"].IsObj());

		material.ambient_color = this->get_color(json["ambient_color"].GetObj());
	}

	return material;

}

/**
* Get the JSON object position (an {x: 1, y: 1, z: 1} obj)
*
* @param json json object containing the previously mentioned data.
* @return glm::vec3 position
*/
glm::vec3 EnvironmentLoader::get_position(json_object json)
{
	assert(json.HasMember("x"));
	assert(json.HasMember("y"));
	assert(json.HasMember("z"));

	assert(json["x"].IsNumber());
	assert(json["y"].IsNumber());
	assert(json["z"].IsNumber());


	return glm::vec3(json["x"].GetFloat(), json["y"].GetFloat(), json["z"].GetFloat());
}

/**
* Get the color defined in JSON (an {r: 1, g: 1, b: 1} obj)
*
* @param json json object containing the previously mentioned data.
* @return glm::vec3 rgb-color
*/
glm::vec3 EnvironmentLoader::get_color(json_object json)
{
	assert(json.HasMember("r"));
	assert(json.HasMember("g"));
	assert(json.HasMember("b"));

	assert(json["r"].IsNumber());
	assert(json["g"].IsNumber());
	assert(json["b"].IsNumber());

	return glm::vec3(json["r"].GetFloat(), json["g"].GetFloat(), json["b"].GetFloat());
}

/**
* Get the instance of the singleton environment loader.
*
* @return A pointer to the EnvironmentLoader singleton
*/
EnvironmentLoader* EnvironmentLoader::get_instance()
{

	if (EnvironmentLoader::instance == nullptr) {
		instance = new EnvironmentLoader();
	}

	return EnvironmentLoader::instance;
}
