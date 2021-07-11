#include "environmentmanager.h"

// The single instance for the environment manager.
EnvironmentManager* EnvironmentManager::instance{ nullptr };

EnvironmentManager::EnvironmentManager()
{
}

/**
* EnvironmentManager destructor.
*/
EnvironmentManager::~EnvironmentManager()
{
	// delete all the entities.
	for (Entity* entity : this->entities)
		delete entity;

	// clear the list of nullptrs
	entities.clear();
	delete instance;
}

EnvironmentManager* EnvironmentManager::get_instance()
{

	if (EnvironmentManager::instance == nullptr) // create an instance if none exists yet.
		instance = new EnvironmentManager();
	

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
