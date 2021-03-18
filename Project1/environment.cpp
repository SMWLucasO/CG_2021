#include "environment.h"

void Environment::init(EnvironmentManager& env_manager, std::string _folder)
{
	folder = _folder;
	for (const auto& entry : std::filesystem::directory_iterator(folder))
	{
		if (!entry.exists() || !entry.is_regular_file()) continue;

		EnvironmentLoader::get_instance()->load_environment(env_manager, entry.path().string());
	}
}

void Environment::refresh_environment(EnvironmentManager& env_manager)
{
	env_manager.clear_entities();
	init(env_manager, folder);
}
