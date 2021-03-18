#include "environmentloader.h"

EnvironmentLoader* EnvironmentLoader::instance{ nullptr };

EnvironmentLoader::EnvironmentLoader()
{
}

EnvironmentLoader::~EnvironmentLoader()
{
	delete instance;
}

void EnvironmentLoader::load_environment(EnvironmentManager& env_manager, std::string path)
{
	
		rapidjson::Document document = this->load_json_from_file(path); // todo loop through each file in folder.

		assert(document.IsObj());
		assert(document.HasMember("geomtype"));
		assert(document.HasMember("shader"));
		assert(document.HasMember("data_points"));
		assert(document["data_points"].IsArray());

		std::string geom_type = document["geomtype"].GetString();
		std::string shader_name = document["shader"].GetString();

		Geometry* geom = GeometryManager::get_instance()->get_geometry_by_name(geom_type);
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

			env_manager.add(EnvironmentEntity(geom, this->load_position(object["position"].GetObj()), this->load_transformations(object)));
		}	
}

Transformations EnvironmentLoader::load_transformations(json_object json)
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

glm::vec3 EnvironmentLoader::load_position(json_object json)
{
	assert(json.HasMember("x"));
	assert(json.HasMember("y"));
	assert(json.HasMember("z"));

	assert(json["x"].IsNumber());
	assert(json["y"].IsNumber());
	assert(json["z"].IsNumber());


	return glm::vec3(json["x"].GetFloat(), json["y"].GetFloat(), json["z"].GetFloat());
}

rapidjson::Document EnvironmentLoader::load_json_from_file(std::string path)
{
	std::ifstream file(path);

	std::stringstream output;

	std::string input;
	while (file >> input) {
		output << input;
	}

	rapidjson::Document document;
	document.Parse(output.str().c_str());

	return document;
}

EnvironmentLoader* EnvironmentLoader::get_instance()
{

	if (EnvironmentLoader::instance == nullptr) {
		instance = new EnvironmentLoader();
	}

	return EnvironmentLoader::instance;
}
