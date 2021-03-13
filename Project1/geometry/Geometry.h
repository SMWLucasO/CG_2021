#pragma once

#include <iostream>
#include <vector>

#include "materials/Material.h"
#include "materials/BasicMaterial.h"

#include "../world/camera/Camera.h"

#include <GL/glew.h>
#include <glm/glm.hpp>

struct Transformations {
	glm::vec3 rotation;
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
	
public:
	Geometry(Material material, glm::vec3 position);
	Geometry(Material material);
	Geometry();
	
	virtual void render(Camera& camera);

	Transformations get_transformations();
	void set_transformations(Transformations transformations);

	Material get_material();
	void set_material(Material material);

	glm::vec3 get_position();
	void set_position(glm::vec3 position);

};

