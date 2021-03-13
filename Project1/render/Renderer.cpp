#include "Renderer.h"

void Renderer::render(std::vector<Geometry>& environment, Camera camera)
{
	for (Geometry& geometry : environment) {
		geometry.render(camera);
	}
}
