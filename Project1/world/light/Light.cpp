#include "Light.h"

glm::vec3 Light::get_position()
{
    return this->position;
}

void Light::set_position(glm::vec3 position)
{
    this->position = position;
}

glm::vec3 Light::get_ambient_color()
{
    return this->ambient_color;
}

void Light::set_ambient_color(glm::vec3 ambient_color)
{
    this->ambient_color = ambient_color;
}

glm::vec3 Light::get_diffuse_color()
{
    return this->diffuse_color;
}

void Light::set_diffuse_color(glm::vec3 diffuse_color)
{
    this->diffuse_color = diffuse_color;
}
