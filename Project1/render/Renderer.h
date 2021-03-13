#pragma once

#include <vector>

#include "../geometry/Geometry.h"
#include "../world/camera/Camera.h"

class Renderer
{
public:
	void render(std::vector<Geometry> &environment, Camera camera, float screen_width, float screen_height);
};

