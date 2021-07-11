#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "entity.h"
#include "camera.h"
#include "lighting.h"
#include "shadingmanager.h"
#include "geometry.h"
#include "shader.h"

struct Material {
	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 0.3);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;
};

class Mesh: public Entity
{
private:
	// A pointer to the geometry which this mesh in the world is constructed from.
	Geometry* geometry;

	// The material of this mesh.
	Material material = Material();

	// the type of the shader program this mesh uses.
	ShaderType shader_type = ShaderType::Phong;

	// boolean determining whether the mesh should render a texture.
	bool texture_enabled = false;

	// The Mesh's VAO, containing our vertices, normals and uvs.
	GLuint vao;

	// ID to be used to send a position to the shader program.
	GLuint position_id;
	
	// ID to be used to send a normal to the shader program
	GLuint normal_id;

	// ID to be used to send a UV to the shader program.
	GLuint uv_id;

	// memory buffer for vertices.
	GLuint vbo_vertices;

	// memory buffer for normals.
	GLuint vbo_normals;

	// memory buffer for uvs.
	GLuint vbo_uvs;
public:

	Mesh(Geometry* geometry, glm::vec3 position);
	Mesh(Geometry* geometry, glm::vec3 position, Transformations transformations);

	/**
	* Set up the mesh for rendering.
	*/
	void setup();

	/**
	* Render our mesh without applying any new transformations.
	*/
	void render();

	/**
	* Render the mesh, applying additional transformations.
	*
	* @param additional_transformations a mat4 containing additional transformations such as rotations.
	*/
	void render_with_additional_transformations(glm::mat4 additional_transformations);

	/**
	* Set the material power for this mesh.
	*
	* @param power the 'shininess' of the mesh.
	*/
	void set_material_power(float power);
	
	/**
	* Get the Material of this mesh.
	*
	* @return Material
	*/
	Material get_material();

	/**
	* Set the Material of this mesh.
	*
	* @param material a material struct with data in it.
	*/
	void set_material(Material material);

	/**
	* Set the shader type of this mesh
	*
	* @param shader_type the type of shader to be applied to this mesh.
	*/
	void set_shader_type(ShaderType shader_type);

	/**
	* Set whether a texture should be rendered for this mesh.
	*
	* @param texture_enabled bool determining whether the texture should be enabled.
	*/
	void set_texture_enabled(bool texture_enabled);

	/**
	* A boolean determining whether the texture is enabled.
	*
	* @return bool
	*/
	bool is_texture_enabled();
};

