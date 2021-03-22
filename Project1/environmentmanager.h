#pragma once

#include <vector>

#include "entity.h"
#include "environment_entity.h"

class EnvironmentManager {
private:
	std::vector<Entity*> entities;

	static EnvironmentManager* instance;

	EnvironmentManager();
	~EnvironmentManager();
public:

	EnvironmentManager(EnvironmentManager& environment_manager) = delete;
	EnvironmentManager(const EnvironmentManager& environment_manager) = delete;

	void operator =(const EnvironmentManager&) = delete;

	static EnvironmentManager* get_instance();

	void add(Entity* entity);
	void clear_entities();

	void render();


};