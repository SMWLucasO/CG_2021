#pragma once


#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../Visual.h"

class ColorVisual: public Visual
{
private:
	std::vector<glm::vec3> colors;
public:
	ColorVisual();
	virtual void bind_visual_vbo(GLuint program_id);
	virtual void bind_visual_vao(GLuint program_id);
	void set_color(int vertex_vector_size, glm::vec3 color);
};

