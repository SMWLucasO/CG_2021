#include "mesh.h"

Mesh::Mesh(Geometry* geometry, glm::vec3 position, Transformations transformations)
{
	this->geometry = geometry;
	this->set_transformations(transformations);
	this->get_transformations().position = position;
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

void Mesh::render() {
	glm::mat4 identity = glm::mat4();
	Mesh::render_with_additional_transformations(identity);
}

void Mesh::render_with_additional_transformations(glm::mat4 additional_transformations)
{
	Shader& program = 
		ShadingManager::get_instance()->get_shader(this->shader_type);

	glUseProgram(program.get_id());
	
	glBindTexture(GL_TEXTURE_2D, this->geometry->get_texture().texture_id);

	glm::mat4 mv = Camera::get_instance()->get_view() * (additional_transformations * this->get_transformations().get_model());
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


Material Mesh::get_material()
{
	return this->material;
}

void Mesh::set_material(Material material)
{
	this->material = material;
}


void Mesh::set_shader_type(ShaderType type)
{
	this->shader_type = type;
}

void Mesh::set_texture_enabled(bool texture_enabled)
{
	this->texture_enabled = texture_enabled;
}

bool Mesh::is_texture_enabled()
{
	return this->texture_enabled;
}
