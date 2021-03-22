#include "environment_entity_group.h"

void EnvironmentEntityGroup::add(EnvironmentEntity entity)
{
	entity.set_position(this->position + entity.get_position());
	entities.push_back(entity);
}

void EnvironmentEntityGroup::render()
{
	for (EnvironmentEntity& entity: this->entities)
		entity.render();
}

void EnvironmentEntityGroup::setup()
{
	for (EnvironmentEntity& entity : this->entities)
		entity.setup();
}
