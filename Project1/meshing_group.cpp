#include "mesh_grouping.h"

void MeshGrouping::add(Mesh entity)
{
	entity.set_position(this->position + entity.get_position());
	entity.set_texture_enabled(true);
	entity.setup();
	
	entities.push_back(entity);
}

void MeshGrouping::render()
{
	for (Mesh& entity: this->entities)
		entity.render();
}

void MeshGrouping::setup()
{
	for (Mesh& entity : this->entities)
		entity.setup();
}
