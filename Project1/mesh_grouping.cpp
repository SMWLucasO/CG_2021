#include "mesh_grouping.h"

void MeshGrouping::add(Mesh* mesh_to_add)
{
	mesh_to_add->set_position(this->get_transformations().position + mesh_to_add->get_position());
	mesh_to_add->set_texture_enabled(true);
	mesh_to_add->setup();
	
	entities.push_back(mesh_to_add);
}

void MeshGrouping::render()
{
	for (Mesh* entity: this->entities)
		entity->render_with_additional_transformations(this->get_transformations().get_model());
}

void MeshGrouping::set_shader_type(ShaderType shader_type)
{
	for (Mesh* entity : this->entities)
		entity->set_shader_type(shader_type);
}

void MeshGrouping::set_texture_enabled(bool enabled)
{
	for (Mesh* entity : this->entities)
		entity->set_texture_enabled(enabled);
}

void MeshGrouping::setup()
{
	for (Mesh* entity: this->entities)
		entity->setup();
}
