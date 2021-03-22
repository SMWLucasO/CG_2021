#include "environmentmanager.h"

EnvironmentManager* EnvironmentManager::instance{ nullptr };

EnvironmentManager::EnvironmentManager()
{
}

EnvironmentManager::~EnvironmentManager()
{
	for (Entity* entity : this->entities)
		delete entity;

	entities.clear();
	delete instance;
}


EnvironmentManager* EnvironmentManager::get_instance()
{

	if (EnvironmentManager::instance == nullptr) {
		instance = new EnvironmentManager();
	}

	return EnvironmentManager::instance;
}

void EnvironmentManager::add(Entity* entity)
{
	this->entities.push_back(entity);
}

void EnvironmentManager::clear_entities()
{
	entities.clear();
}

void EnvironmentManager::render()
{
	for (Entity* entity : this->entities)
		entity->render();
}
