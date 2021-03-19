#pragma once

#include <filesystem>
#include <string>

#include "environmentmanager.h"
#include "geometrymanager.h"

#include "geometryloader.h"
#include "environmentloader.h"

namespace Environment {

	static std::string folder;

	void init(EnvironmentManager& env_manager, GeometryManager& geom_manager, std::string folder);
	void refresh_environment(EnvironmentManager& env_manager, GeometryManager& geom_manager);
};

