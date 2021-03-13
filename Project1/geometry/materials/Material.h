#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../shading/shading.h"
#include "visual/Visual.h"

class Material
{
private:
	GLuint uniform_mv;
	GLuint uniform_projection;

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	glm::mat4 mv;

protected:
	ShaderProgram* shader_program;
	Visual visual;
public:
	ShaderProgram* get_shader();

	virtual void setup_uniforms(GLuint program_id);
	virtual void send_uniforms(GLuint program_id);
	virtual void fill_uniforms(GLuint program_id);
	
	void set_model(glm::mat4 model);
	void set_view(glm::mat4 view);
	void set_projection(glm::mat4 projection);

	Visual get_visual();
	void set_visual(Visual visual);
};

