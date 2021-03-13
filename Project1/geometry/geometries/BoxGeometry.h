#pragma once

#include "../Geometry.h"

class BoxGeometry: public Geometry
{
	void render(Camera& camera, float screen_width, float screen_height);
};

