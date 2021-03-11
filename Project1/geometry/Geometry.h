#pragma once

#include "materials/Material.h"
#include "materials/BasicMaterial.h"

#include <glm/glm.hpp>

#include <iostream>

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
	float width = 1;
	float height = 1;
	float depth = 1;
public:
	Geometry(Material material, glm::vec3 position);
	Geometry(Material material);
	Geometry();
	
	Transformations get_transformations();
	void set_transformations(Transformations transformations);

	Material get_material();
	void set_material(Material material);

	glm::vec3 get_position();
	void set_position(glm::vec3 position);

};

