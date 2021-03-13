#pragma once

#include <iostream>
#include <vector>

#include "materials/Material.h"
#include "materials/BasicMaterial.h"

#include "../world/camera/Camera.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "materials/visual/Visual.h"

struct Transformations {
	float rotation_x;
	float rotation_y;
	float rotation_z;
	glm::vec3 translation;
	glm::vec3 scaling;
};


class Geometry
{
private:
	Transformations transformations;
	Material material;
	glm::vec3 position;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> faces;

protected:
	GLuint vertex_array_object;
	GLuint position_id;
	GLuint vbo_vertices;
	GLuint ibo_faces;

	virtual void init_buffers(GLuint program_id);
public:
	Geometry(Material material, glm::vec3 position);
	Geometry(Material material);
	Geometry();
	
	virtual void render(Camera& camera, float screen_width, float screen_height);

	void init_matrices(Camera& camera, float screen_width, float screen_height);

	Transformations get_transformations();
	void set_transformations(Transformations transformations);

	Material get_material();
	void set_material(Material material);

	glm::vec3 get_position();
	void set_position(glm::vec3 position);

};

