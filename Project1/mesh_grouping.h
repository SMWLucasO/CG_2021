#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "entity.h"
#include "mesh.h"



class MeshGrouping: public Entity
{
private:
	// the meshes in this mesh grouping.
	std::vector<Mesh*> entities;
public:

	/**
	* Add a mesh to the mesh grouping.
	*
	* @param mesh_to_add the mesh to add to the grouping.
	*/
	void add(Mesh* mesh_to_add);

	/**
	* Render the mesh grouping.
	*/
	void render();

	/**
	* Set the shader type for all current entities of this mesh grouping.
	* 
	* @param shader_type the shader type to be set for all entities of this group.
	*/
	void set_shader_type(ShaderType shader_type);

	/**
	* Set whether the texture is enabled for all current entities of this mesh grouping.
	*
	* @param enabled a bool determining whether the texture should be enabled or disabled.
	*/
	void set_texture_enabled(bool enabled);

	/**
	* Set up the mesh grouping.
	*/
	void setup();

};

