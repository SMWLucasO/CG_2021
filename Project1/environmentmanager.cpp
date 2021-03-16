#include "environmentmanager.h"

EnvironmentManager* EnvironmentManager::instance{ nullptr };
std::mutex EnvironmentManager::_mutex;


EnvironmentManager::EnvironmentManager()
{
}

EnvironmentManager::~EnvironmentManager()
{
	delete instance;
}


EnvironmentManager* EnvironmentManager::get_instance() {

	std::lock_guard<std::mutex> lock(_mutex);

	if (EnvironmentManager::instance == nullptr) {
		instance = new EnvironmentManager();
	}

	return EnvironmentManager::instance;
}