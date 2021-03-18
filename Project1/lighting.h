#pragma once

#include <glm/glm.hpp>

class Lighting
{
private:
	static Lighting* instance;

	glm::vec3 position;

	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 1.0);



	Lighting();
	~Lighting();

public:
	static Lighting* get_instance();

	Lighting(const Lighting&) = delete;
	Lighting(Lighting&) = delete;

	void operator =(const Lighting&) = delete;

	glm::vec3 get_position();
	void set_position(glm::vec3 position);

	glm::vec3 get_ambient_color();
	void set_ambient_color(glm::vec3 ambient_color);

	glm::vec3 get_diffuse_color();
	void set_diffuse_color(glm::vec3 diffuse_color);

	

};

