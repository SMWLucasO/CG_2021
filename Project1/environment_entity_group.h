#pragma once

#include <vector>

#include "entity.h"
#include "environment_entity.h"

class EnvironmentEntityGroup: public Entity
{
private:
	glm::vec3 position = glm::vec3(0,0,0);
	std::vector<EnvironmentEntity> entities;
public:

	void add(EnvironmentEntity entity);

	void render();

	void setup();

};

