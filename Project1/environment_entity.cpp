#include "environment_entity.h"
#include "camera.cpp"

EnvironmentEntity::EnvironmentEntity(Geometry& geometry, glm::vec3 position, Transformations transformations)
{
	this->geometry = &geometry;
	this->position = position;
	this->transformations = transformations;
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

	glGenBuffers(1, &this->vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_vertices);
	glBufferData(
		GL_ARRAY_BUFFER,
		this->geometry->get_uvs().size() * sizeof(glm::vec2),
		&this->geometry->get_uvs()[0],
		GL_STATIC_DRAW
	);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	this->normal_id = glGetAttribLocation(program_id, "normal");
	this->position_id = glGetAttribLocation(program_id, "position");

	glGenVertexArrays(1, &this->vao);

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
	glVertexAttribPointer(this->uv_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(this->uv_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	this->uniforms.uniform_mv = glGetUniformLocation(program_id, "mv");
	this->uniforms.uniform_proj = glGetUniformLocation(program_id, "projection");
	this->uniforms.uniform_light_pos = glGetUniformLocation(program_id, "light_pos");
	this->uniforms.uniform_specular = glGetUniformLocation(program_id, "mat_specular");
	this->uniforms.uniform_material_power = glGetUniformLocation(program_id, "mat_power");
	this->uniforms.uniform_material_ambient = glGetUniformLocation(program_id, "mat_ambient");
	this->uniforms.uniform_material_diffuse = glGetUniformLocation(program_id, "mat_diffuse");

	glm::mat4 mv = Camera::get_instance()->get_view() * this->get_model();

	glUseProgram(program_id);

	// Fill uniform vars
	glUniformMatrix4fv(this->uniforms.uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));
	glUniformMatrix4fv(this->uniforms.uniform_proj, 1, GL_FALSE, glm::value_ptr(Camera::get_instance()->get_projection()));
	
	//glUniform3fv(this->uniforms.uniform_light_pos, 1, glm::value_ptr(light_position));
	
	glUniform3fv(this->uniforms.uniform_material_ambient, 1, glm::value_ptr(this->geometry->get_material().ambient_color));
    glUniform3fv(this->uniforms.uniform_material_diffuse, 1, glm::value_ptr(this->geometry->get_material().diffuse_color));
	glUniform1f(this->uniforms.uniform_material_power, this->geometry->get_material().power);
	glUniform3fv(this->uniforms.uniform_specular, 1, glm::value_ptr(this->geometry->get_material().specular));

}

void EnvironmentEntity::render()
{
	// do something here for rendering
}

EnvironmentEntity::EnvironmentEntity(Geometry& geometry, glm::vec3 position) : EnvironmentEntity(geometry, position)
{
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
