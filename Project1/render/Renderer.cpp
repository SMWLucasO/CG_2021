#include "Renderer.h"

void Renderer::render(std::vector<Geometry>& environment, Camera camera, float screen_width, float screen_height)
{
	for (Geometry& geometry : environment) {
		geometry.render(camera, screen_width, screen_height);
	}
}
