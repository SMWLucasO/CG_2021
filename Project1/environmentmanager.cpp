#include "environmentmanager.h"

EnvironmentManager* EnvironmentManager::instance{ nullptr };

EnvironmentManager::EnvironmentManager()
{
}

EnvironmentManager::~EnvironmentManager()
{
	delete instance;
}


EnvironmentManager* EnvironmentManager::get_instance()
{

	if (EnvironmentManager::instance == nullptr) {
		instance = new EnvironmentManager();
	}

	return EnvironmentManager::instance;
}

void EnvironmentManager::add(EnvironmentEntity entity)
{
	this->entities.push_back(entity);
}

void EnvironmentManager::render()
{
	for (EnvironmentEntity& entity : this->entities)
		entity.render();
}
