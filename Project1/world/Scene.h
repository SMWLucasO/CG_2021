#pragma once

#include <vector>
#include <filesystem>
#include <iostream>

#include "../geometry/Geometry.h"
#include "../loaders/environment/EnvironmentLoader.h"

#include "camera/Camera.h"
#include "light/Light.h"

class Scene
{
private:
	std::vector<Geometry> environment;
public:
	void init(std::string data_environment_folder);
};

