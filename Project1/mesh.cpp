#include "mesh.h"

Mesh::Mesh(Geometry* geometry, glm::vec3 position, Transformations transformations)
{
	this->geometry = geometry;
	this->position = position;
	this->transformations = transformations;
}

Mesh::Mesh(Geometry* geometry, glm::vec3 position) : Mesh(geometry, position, Transformations())
{
}

void Mesh::setup()
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

	glGenBuffers(1, &this->vbo_uvs);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_uvs);
	glBufferData(
		GL_ARRAY_BUFFER,
		this->geometry->get_uvs().size() * sizeof(glm::vec2),
		&this->geometry->get_uvs()[0],
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

	// Bind uvs to vao
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_uvs);
	glVertexAttribPointer(this->uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(this->uv_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind vertices to vao
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_vertices);
	glVertexAttribPointer(this->position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(this->position_id);
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
	uniforms.uniform_texture_enabled = glGetUniformLocation(program_id, "texture_enabled");

	this->geometry->set_uniforms(uniforms);

	glm::mat4 mv = Camera::get_instance()->get_view() * this->get_model();
}

void Mesh::render()
{
	GLuint program_id = 
		ShadingManager::get_instance()->get_shader(this->shader_type).get_id();

	glUseProgram(program_id);
	
	glBindTexture(GL_TEXTURE_2D, this->geometry->get_texture().texture_id);

	glm::mat4 mv = Camera::get_instance()->get_view() * this->get_model();

	Lighting* lighting = Lighting::get_instance();

	// send uniforms and stuff.
	glUniformMatrix4fv(this->geometry->get_uniforms().uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));
	glUniformMatrix4fv(this->geometry->get_uniforms().uniform_proj, 1, GL_FALSE, glm::value_ptr(Camera::get_instance()->get_projection()));
	
	glUniform3fv(this->geometry->get_uniforms().uniform_light_pos, 1, glm::value_ptr(lighting->get_position()));

	glUniform3fv(this->geometry->get_uniforms().uniform_material_ambient, 1, glm::value_ptr(this->material.ambient_color));
	glUniform3fv(this->geometry->get_uniforms().uniform_material_diffuse, 1, glm::value_ptr(this->material.diffuse_color));
	glUniform3fv(this->geometry->get_uniforms().uniform_specular, 1, glm::value_ptr(this->material.specular));
	glUniform1f(this->geometry->get_uniforms().uniform_material_power, this->material.power);

	glUniform1i(this->geometry->get_uniforms().uniform_texture_enabled, this->texture_enabled);

	// send VAO
	glBindVertexArray(this->vao);
	glDrawArrays(GL_TRIANGLES, 0, this->geometry->get_vertices().size());
	glBindVertexArray(0);

}


glm::vec3 Mesh::get_position()
{
	return this->position;
}

void Mesh::set_position(glm::vec3 position)
{
	this->position = position;
}

Transformations Mesh::get_transformations()
{
	return this->transformations;
}

void Mesh::set_transformations(Transformations transformations)
{
	this->transformations = transformations;
}

Material Mesh::get_material()
{
	return this->material;
}

void Mesh::set_material(Material material)
{
	this->material = material;
}

void Mesh::set_rotations(glm::vec3 rotations)
{
	this->transformations.rotations = rotations;
}

void Mesh::set_shader_type(ShaderType type)
{
	this->shader_type = type;
}

glm::mat4 Mesh::get_model()
{
	glm::mat4 model;

	// scaling
	model = glm::scale(model, this->transformations.scaling);

	// rotation
	model = glm::rotate(model, glm::radians(this->transformations.rotations.x), glm::vec3(1, 0, 0));
	model = glm::rotate(model, glm::radians(this->transformations.rotations.y), glm::vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(this->transformations.rotations.z), glm::vec3(0, 0, 1));

	// translation
	model = glm::translate(model, this->position);

	return model;
}

glm::vec3 Mesh::get_rotations()
{
	return this->transformations.rotations;
}

void Mesh::set_scaling(glm::vec3 scaling)
{
	this->transformations.scaling = scaling;
}

glm::vec3 Mesh::get_scaling()
{
	return this->transformations.scaling;
}

void Mesh::set_texture_enabled(bool texture_enabled)
{
	this->texture_enabled = texture_enabled;
}

bool Mesh::is_texture_enabled()
{
	return this->texture_enabled;
}
