#pragma once

#include <vector>

#include "geometrymanager.h"
#include "entity.h"
#include "mesh.h"

class EnvironmentManager {
private:

	// List containing all the entities in the world.
	std::vector<Entity*> entities;

	// The single instance for the environment manager.
	static EnvironmentManager* instance;

	EnvironmentManager();
	~EnvironmentManager();
public:

	EnvironmentManager(EnvironmentManager& environment_manager) = delete;
	EnvironmentManager(const EnvironmentManager& environment_manager) = delete;

	void operator =(const EnvironmentManager&) = delete;

	/**
	* Get the single instance of the EnvironmentManager.
	*
	* @return EnvironmentManager*
	*/
	static EnvironmentManager* get_instance();

	/**
	* Add an entity to the world.
	*/
	void add(Entity* entity);

	/**
	* Clear the world of all entities.
	*/
	void clear_entities();

	/**
	* Render all the entities within the world.
	*/
	void render();


};