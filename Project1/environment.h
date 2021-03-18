#pragma once

#include <filesystem>
#include <string>

#include "environmentloader.h"
#include "environmentmanager.h"
#include "geometrymanager.h"

namespace Environment {
	void init(EnvironmentManager& env_manager, std::string folder);
};

