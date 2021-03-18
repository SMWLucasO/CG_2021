#include "environment_entity.h"

EnvironmentEntity::EnvironmentEntity(Geometry* geometry, glm::vec3 position, Transformations transformations)
{
	this->geometry = geometry;
	this->position = position;
	this->transformations = transformations;

	// only init once.
	if(!geometry->is_inited())
		this->setup();
}

EnvironmentEntity::EnvironmentEntity(Geometry* geometry, glm::vec3 position) : EnvironmentEntity(geometry, position, Transformations())
{
}

void EnvironmentEntity::setup()
{
	GLuint program_id = 
		ShadingManager::get_instance()->get_shader(this->shader_type).get_id();

	glGenBuffers(1, &this->vbo_normals);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_normals);
	glBufferData(
		GL_ARRAY_BUFFER,
		this->geometry->get_normals().size() * sizeof(glm::vec3),
		&this->geometry->get_normals()[0],
		GL_STATIC_DRAW
	);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &this->vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_vertices);
	glBufferData(
		GL_ARRAY_BUFFER,
		this->geometry->get_vertices().size() * sizeof(glm::vec3),
		&this->geometry->get_vertices()[0],
		GL_STATIC_DRAW
	);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &this->vbo_uvs);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_uvs);
	glBufferData(
		GL_ARRAY_BUFFER,
		this->geometry->get_uvs().size() * sizeof(glm::vec2),
		&this->geometry->get_uvs()[0],
		GL_STATIC_DRAW
	);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	this->normal_id = glGetAttribLocation(program_id, "normal");
	this->position_id = glGetAttribLocation(program_id, "position");
	this->uv_id = glGetAttribLocation(program_id, "uv");

	glGenVertexArrays(1, &this->vao);

	glBindVertexArray(this->vao);

	// Bind normals to vao
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_normals);
	glVertexAttribPointer(this->normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(this->normal_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind vertices to vao
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_vertices);
	glVertexAttribPointer(this->position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(this->position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind uvs to vao
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_uvs);
	glVertexAttribPointer(this->uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(this->uv_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	Uniforms uniforms = Uniforms();

	uniforms.uniform_mv = glGetUniformLocation(program_id, "mv");
	uniforms.uniform_proj = glGetUniformLocation(program_id, "projection");
	uniforms.uniform_light_pos = glGetUniformLocation(program_id, "light_pos");
	uniforms.uniform_specular = glGetUniformLocation(program_id, "mat_specular");
	uniforms.uniform_material_power = glGetUniformLocation(program_id, "mat_power");
	uniforms.uniform_material_ambient = glGetUniformLocation(program_id, "mat_ambient");
	uniforms.uniform_material_diffuse = glGetUniformLocation(program_id, "mat_diffuse");

	this->geometry->set_uniforms(uniforms);

	glm::mat4 mv = Camera::get_instance()->get_view() * this->get_model();

	glUseProgram(program_id);

	Lighting* lighting = Lighting::get_instance();

	// Fill uniform vars
	glUniformMatrix4fv(this->geometry->get_uniforms().uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));
	glUniformMatrix4fv(this->geometry->get_uniforms().uniform_proj, 1, GL_FALSE, glm::value_ptr(Camera::get_instance()->get_projection()));
	
	glUniform3fv(this->geometry->get_uniforms().uniform_light_pos, 1, glm::value_ptr(lighting->get_position()));
	
	glUniform3fv(this->geometry->get_uniforms().uniform_material_ambient, 1, glm::value_ptr(lighting->get_ambient_color()));
    glUniform3fv(this->geometry->get_uniforms().uniform_material_diffuse, 1, glm::value_ptr(lighting->get_diffuse_color()));
	glUniform1f(this->geometry->get_uniforms().uniform_material_power, this->geometry->get_material().power);
	glUniform3fv(this->geometry->get_uniforms().uniform_specular, 1, glm::value_ptr(this->geometry->get_material().specular));

	this->geometry->set_inited(true);
}

void EnvironmentEntity::render()
{
	GLuint program_id = 
		ShadingManager::get_instance()->get_shader(this->shader_type).get_id();

	glUseProgram(program_id);
	//glBindTexture(GL_TEXTURE_2D, this->geometry->get_texture().texture_id);

	glm::mat4 mv = Camera::get_instance()->get_view() * this->get_model();

	Lighting* lighting = Lighting::get_instance();

	// send uniforms and stuff.
	glUniformMatrix4fv(this->geometry->get_uniforms().uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));
	glUniformMatrix4fv(this->geometry->get_uniforms().uniform_proj, 1, GL_FALSE, glm::value_ptr(Camera::get_instance()->get_projection()));
	
	glUniform3fv(this->geometry->get_uniforms().uniform_material_ambient, 1, glm::value_ptr(lighting->get_ambient_color()));
	glUniform3fv(this->geometry->get_uniforms().uniform_material_diffuse, 1, glm::value_ptr(lighting->get_diffuse_color()));
	glUniform3fv(this->geometry->get_uniforms().uniform_specular, 1, glm::value_ptr(this->geometry->get_material().specular));
	glUniform1f(this->geometry->get_uniforms().uniform_material_power, this->geometry->get_material().power);

	// send VAO
	glBindVertexArray(this->vao);
	glDrawArrays(GL_TRIANGLES, 0, this->geometry->get_vertices().size());
	glBindVertexArray(0);

}


glm::vec3 EnvironmentEntity::get_position()
{
	return this->position;
}

void EnvironmentEntity::set_position(glm::vec3 position)
{
	this->position = position;
}

Transformations EnvironmentEntity::get_transformations()
{
	return this->transformations;
}

void EnvironmentEntity::set_transformations(Transformations transformations)
{
	this->transformations = transformations;
}

void EnvironmentEntity::set_rotations(glm::vec3 rotations)
{
	this->transformations.rotations = rotations;
}

glm::mat4 EnvironmentEntity::get_model()
{
	glm::mat4 model;

	// scaling
	glm::scale(model, this->transformations.scaling);

	// rotation
	glm::rotate(model, glm::radians(this->transformations.rotations.x), glm::vec3(1, 0, 0));
	glm::rotate(model, glm::radians(this->transformations.rotations.y), glm::vec3(0, 1, 0));
	glm::rotate(model, glm::radians(this->transformations.rotations.z), glm::vec3(0, 0, 1));

	// translation
	glm::translate(model, this->transformations.translation);

	return model;
}

glm::vec3 EnvironmentEntity::get_rotations()
{
	return this->transformations.rotations;
}

void EnvironmentEntity::set_scaling(glm::vec3 scaling)
{
	this->transformations.scaling = scaling;
}

glm::vec3 EnvironmentEntity::get_scaling()
{
	return this->transformations.scaling;
}

void EnvironmentEntity::set_translations(glm::vec3 translations)
{
	this->transformations.translation = translations;
}

glm::vec3 EnvironmentEntity::get_translations()
{
	return this->transformations.translation;
}
