#include "entity.h"

Transformations& Entity::get_transformations()
{
    return this->transformations;
}

void Entity::set_transformations(Transformations transformations)
{
    this->transformations = transformations;
}
