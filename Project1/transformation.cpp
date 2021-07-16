#include "transformation.h"

glm::mat4 Transformations::get_model()
{
	glm::mat4 model;

	// translation
	model = glm::translate(model, this->position);

	// rotation
	model = glm::rotate(model, glm::radians(this->rotations.x), glm::vec3(1, 0, 0));
	model = glm::rotate(model, glm::radians(this->rotations.y), glm::vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(this->rotations.z), glm::vec3(0, 0, 1));

	// scaling
	model = glm::scale(model, this->scaling);


	return model;
}