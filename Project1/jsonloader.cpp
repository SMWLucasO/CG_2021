#include "jsonloader.h"

JsonLoader* JsonLoader::instance{ nullptr };

JsonLoader::JsonLoader()
{
}

JsonLoader::~JsonLoader()
{
	delete instance;
}

rapidjson::Document JsonLoader::load_json_from_file(std::string path)
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

/**
* Get the instance of the singleton environment loader.
*
* @return A pointer to the EnvironmentLoader singleton
*/
JsonLoader* JsonLoader::get_instance()
{

	if (JsonLoader::instance == nullptr) {
		instance = new JsonLoader();
	}

	return JsonLoader::instance;
}