#include "ColorVisual.h"

ColorVisual::ColorVisual()
{
	this->colors = std::vector<glm::vec3>();
}

void ColorVisual::bind_visual_vbo(GLuint program_id)
{
	glGenBuffers(1, &this->vbo_visual);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_visual);
	glBufferData(GL_ARRAY_BUFFER, this->colors.size() * sizeof(glm::vec3), &this->colors[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ColorVisual::bind_visual_vao(GLuint program_id)
{
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_visual);
	glVertexAttribPointer(this->visual_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(this->visual_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ColorVisual::set_color(int vertex_vector_size, glm::vec3 color)
{
	for (int i = 0; i < vertex_vector_size; i++) {
		this->colors.push_back(glm::vec3(color.x, color.y, color.z));
	}
}
