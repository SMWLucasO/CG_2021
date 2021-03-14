#pragma once

#include "../Geometry.h"

#include "../materials/visual/Visual.h"
#include "../materials/visual/visuals/ColorVisual.h"

class BoxGeometry: public Geometry
{
	virtual void render(Camera& camera, float screen_width, float screen_height);
	virtual void init();
};

