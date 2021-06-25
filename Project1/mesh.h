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
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 1.0);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;
};

class Mesh: public Entity
{
private:
	Geometry* geometry;

	Material material = Material();

	ShaderType shader_type = ShaderType::Phong;

	bool texture_enabled = false;

	// OpenGL things
	GLuint vao;

	GLuint position_id;
	GLuint normal_id;
	GLuint uv_id;

	GLuint vbo_vertices;
	GLuint vbo_normals;
	GLuint vbo_uvs;
public:

	Mesh(Geometry* geometry, glm::vec3 position);
	Mesh(Geometry* geometry, glm::vec3 position, Transformations transformations);

	void setup();

	void render();
	void render_with_additional_transformations(glm::mat4 additional_transformations);

	void set_material_power(float power);

	glm::vec3 get_position();
	void set_position(glm::vec3 position);

	Material get_material();
	void set_material(Material material);

	void set_rotations(glm::vec3 rotations);
	glm::vec3 get_rotations();

	void set_scaling(glm::vec3 scaling);
	glm::vec3 get_scaling();

	void set_shader_type(ShaderType type);

	void set_texture_enabled(bool texture_enabled);
	bool is_texture_enabled();
};

