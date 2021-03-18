#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"
#include "lighting.h"
#include "shadingmanager.h"
#include "geometry.h"
#include "shader.h"

struct Transformations {
	glm::vec3 scaling = glm::vec3(1, 1, 1);
	glm::vec3 rotations = glm::vec3(0, 0, 0);
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

	GLuint position_id;
	GLuint normal_id;
	GLuint uv_id;

	GLuint vbo_vertices;
	GLuint vbo_normals;
	GLuint vbo_uvs;
public:

	EnvironmentEntity(Geometry* geometry, glm::vec3 position);
	EnvironmentEntity(Geometry* geometry, glm::vec3 position, Transformations transformations);

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

};

