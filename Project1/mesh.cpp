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
	
	// setup this mesh of the geometry.
	this->geometry->setup(program_id, this->vao, this->vbo_vertices, this->vbo_uvs, this->vbo_normals, this->position_id, this->normal_id, this->uv_id);
}

void Mesh::render()
{
	Shader& program = 
		ShadingManager::get_instance()->get_shader(this->shader_type);

	glUseProgram(program.get_id());
	
	glBindTexture(GL_TEXTURE_2D, this->geometry->get_texture().texture_id);

	glm::mat4 mv = Camera::get_instance()->get_view() * this->get_model();
	Lighting* lighting = Lighting::get_instance();
	
	// send uniforms and stuff.
	glUniform3fv(program.get_uniforms().uniform_material_ambient, 1, glm::value_ptr(this->material.ambient_color));
	glUniform3fv(program.get_uniforms().uniform_material_diffuse, 1, glm::value_ptr(this->material.diffuse_color));
	glUniform3fv(program.get_uniforms().uniform_specular, 1, glm::value_ptr(this->material.specular));
	glUniform1f(program.get_uniforms().uniform_material_power, this->material.power);
	glUniform1i(program.get_uniforms().uniform_texture_enabled, this->texture_enabled);

	glUniformMatrix4fv(program.get_uniforms().uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));

	// send VAO
	glBindVertexArray(this->vao);
	glDrawArrays(GL_TRIANGLES, 0, this->geometry->get_vertices().size());
	glBindVertexArray(0);

}

void Mesh::set_material_power(float power)
{
	this->material.power = power;
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
