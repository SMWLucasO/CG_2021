#pragma once

#include "transformation.h"

class Entity
{
private:
	Transformations transformations = Transformations();
public:
	virtual void setup() = 0;
	virtual void render() = 0;

	Transformations& get_transformations();
	void set_transformations(Transformations transformations);

	glm::vec3 get_position();
	void set_position(glm::vec3 position);

	glm::vec3 get_rotations();
	void set_rotations(glm::vec3 rotations);

	glm::vec3 get_scaling();
	void set_scaling(glm::vec3 scaling);


};

