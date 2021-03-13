#pragma once

#include <GL/glew.h>

class Visual
{
protected:
	GLuint visual_id;
	GLuint vbo_visual;
public:
	virtual void bind_visual_vbo(GLuint program_id);
	virtual void bind_visual_vao(GLuint program_id);
	void set_visual_id(GLuint visual_id);
};

