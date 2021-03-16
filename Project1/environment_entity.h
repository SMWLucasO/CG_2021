#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shadingmanager.h"
#include "geometry.h"
#include "shader.h"

struct Transformations {
	glm::vec3 translation = glm::vec3(0, 0, 0);
	glm::vec3 scaling = glm::vec3(0, 0, 0);
	glm::vec3 rotations = glm::vec3(0, 0, 0);
};

// Maybe these uniforms belong to the shader? Doubtful, but possible.
struct Uniforms {
	GLuint uniform_mv;
	GLuint uniform_p;
	GLuint uniform_proj;
	GLuint uniform_light_pos;
	GLuint uniform_specular;
	GLuint uniform_material_power;
	GLuint uniform_material_ambient;
	GLuint uniform_material_diffuse;
};

class EnvironmentEntity
{
private:
	Transformations transformations;
	Geometry* geometry;

	glm::vec3 position = glm::vec3(0,0,0);
	ShaderType shader_type = ShaderType::Phong;

	// OpenGL things
	GLuint vao;

	Uniforms uniforms;

	GLuint position_id;
	GLuint normal_id;
	GLuint uv_id;

	GLuint vbo_vertices;
	GLuint vbo_normals;
	GLuint vbo_uvs;
public:

	EnvironmentEntity(Geometry& geometry, glm::vec3 position);
	EnvironmentEntity(Geometry& geometry, glm::vec3 position, Transformations transformations);

	void setup();
	void render();

	glm::mat4 get_model();

	glm::vec3 get_position();
	void set_position(glm::vec3 position);

	Transformations get_transformations();
	void set_transformations(Transformations transformations);

	void set_rotations(glm::vec3 rotations);
	glm::vec3 get_rotations();

	void set_scaling(glm::vec3 scaling);
	glm::vec3 get_scaling();

	void set_translations(glm::vec3 translations);
	glm::vec3 get_translations();

};

