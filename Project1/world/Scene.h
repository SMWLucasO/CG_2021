#pragma once

#include <vector>
#include <filesystem>
#include <iostream>

#include "camera/Camera.h"
#include "light/Light.h"

#include "../geometry/Geometry.h"
#include "../loaders/environment/EnvironmentLoader.h"

#include "../render/Renderer.h"

class Scene
{
private:
	std::vector<Geometry> environment;
	Renderer renderer;
public:
	void init(std::string data_environment_folder);
};

