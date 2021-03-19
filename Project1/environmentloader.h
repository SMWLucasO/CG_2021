#pragma once

#include "../vendor/rapidjson/document.h"

#include <glm/glm.hpp>

#include <string>

#include "shadingmanager.h"
#include "geometry.h"
#include "geometrymanager.h"
#include "environmentmanager.h"

#include "jsonloader.h"

class EnvironmentLoader
{
private:
	static EnvironmentLoader* instance;

	EnvironmentLoader();
	~EnvironmentLoader();

	Transformations get_transformations(json_object json);
	Material get_material(Material initial_material, json_object json);
	glm::vec3 get_position(json_object json);

	glm::vec3 get_color(json_object json);
public:
	EnvironmentLoader(EnvironmentLoader& environment_manager) = delete;
	EnvironmentLoader(const EnvironmentLoader& environment_manager) = delete;

	void operator =(const EnvironmentLoader&) = delete;

	static EnvironmentLoader* get_instance();

	void load_environment(EnvironmentManager& env_manager, std::string folder);
};

