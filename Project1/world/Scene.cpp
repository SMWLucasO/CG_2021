#include "Scene.h"

Scene::Scene(float screen_width, float screen_height)
{
	this->renderer = Renderer();
	this->environment = std::vector<Geometry>();
	this->screen_width = screen_width;
	this->screen_height = screen_height;

	this->light = Light();
	this->light.set_position(glm::vec3(0.0f, 10.0f, 0.0f));
}

void Scene::init(std::string data_environment_folder)
{
	EnvironmentLoader envLoader;
	// Load the geometry data from each json file.
	for (const auto& entry : std::filesystem::directory_iterator(data_environment_folder)) {
		if (!entry.exists() || !entry.is_regular_file()) continue;

		// load the geometries
		std::vector<Geometry> geoms = envLoader.load_environment(entry.path().string(), this->camera, this->screen_width, this->screen_height, this->light);
		
		// do not add if there are no geometries.
		if (geoms.size() <= 0) continue;
		
		// add geometries to environment
		this->environment.insert(std::end(this->environment), std::begin(geoms), std::end(geoms));
	}

}

void Scene::render()
{
	this->renderer.render(this->environment, this->camera, this->screen_width, this->screen_height);
}

