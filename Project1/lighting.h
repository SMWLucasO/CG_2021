#pragma once

#include <glm/glm.hpp>

class Lighting
{
private:
	// the single lighting instance.
	static Lighting* instance;

	// the position of the lighting
	glm::vec3 position;

	Lighting();
	~Lighting();

public:
	static Lighting* get_instance();

	Lighting(const Lighting&) = delete;
	Lighting(Lighting&) = delete;

	void operator =(const Lighting&) = delete;

	glm::vec3 get_position();
	void set_position(glm::vec3 position);
};

