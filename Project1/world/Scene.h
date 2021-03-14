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
	
	Camera camera;
	Light light;

	float screen_width = 0;
	float screen_height = 0;
public:
	Scene(float screen_width, float screen_height);
	void init(std::string data_environment_folder);
	void render();



};

