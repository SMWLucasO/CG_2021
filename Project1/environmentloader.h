#pragma once

#include "../vendor/rapidjson/document.h"

#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "shadingmanager.h"
#include "geometry.h"
#include "geometrymanager.h"
#include "environmentmanager.h"

#define json_object rapidjson::GenericObj<true, rapidjson::Value>

class EnvironmentLoader
{
private:
	static EnvironmentLoader* instance;

	EnvironmentLoader();
	~EnvironmentLoader();

	rapidjson::Document load_json_from_file(std::string path);
	Transformations load_transformations(json_object json);
	glm::vec3 load_position(json_object json);

public:

	EnvironmentLoader(EnvironmentLoader& environment_manager) = delete;
	EnvironmentLoader(const EnvironmentLoader& environment_manager) = delete;

	void operator =(const EnvironmentLoader&) = delete;

	static EnvironmentLoader* get_instance();

	void load_environment(EnvironmentManager& env_manager, std::string folder);
};

