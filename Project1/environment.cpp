#include "environment.h"

void Environment::init(EnvironmentManager& env_manager, GeometryManager& geom_manager, std::string _data_folder)
{
	folder = _data_folder;
	
	GeometryLoader::get_instance()->load_geometry(geom_manager, _data_folder + "Geometries.json");
	
	for (const auto& entry : std::filesystem::directory_iterator((folder + "entities/")))
	{
		if (!entry.exists() || !entry.is_regular_file()) continue;

		EnvironmentLoader::get_instance()->load_environment(env_manager, entry.path().string());
	}
}

void Environment::refresh_environment(EnvironmentManager& env_manager, GeometryManager& geom_manager)
{
	env_manager.clear_entities();
	geom_manager.clear_geoms();
	init(env_manager, geom_manager, folder);
}
