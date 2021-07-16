#include "mesh.h"

Mesh::Mesh(Geometry* geometry, glm::vec3 position, Transformations transformations)
{
	this->geometry = geometry;
	this->set_transformations(transformations);
	this->get_transformations().position = position;

	// give a material power between [256, 1024]
	this->material.power = 256 + (rand() % 769);
}

Mesh::Mesh(Geometry* geometry, glm::vec3 position) : Mesh(geometry, position, Transformations())
{
}

void Mesh::setup()
{
	// get the program id for the shader we are using.
	// This lets us render our mesh.
	GLuint program_id = 
		ShadingManager::get_instance()->get_shader(this->shader_type).get_id();
	
	// setup this mesh of the geometry.
	this->geometry->setup(program_id, this->vao, this->vbo_vertices, this->vbo_uvs, this->vbo_normals, this->position_id, this->normal_id, this->uv_id);
}

void Mesh::render() {
	glm::mat4 identity = glm::mat4();
	// call our render method with a 4x4 identity matrix such that no additional transformations will occur.
	Mesh::render_with_additional_transformations(identity);
}

void Mesh::render_with_additional_transformations(glm::mat4 additional_transformations)
{
	// Get the shader which will be used to render 
	Shader& program = 
		ShadingManager::get_instance()->get_shader(this->shader_type);

	glUseProgram(program.get_id());
	
	// bind the texture to the mesh
	glBindTexture(GL_TEXTURE_2D, this->geometry->get_texture().texture_id);

	// Get a Model View matrix calculation to send to the shader
	glm::mat4 mv = Camera::get_instance()->get_view() * (additional_transformations * this->get_transformations().get_model());
	
	// Get the lighing in our world so that we may send this.
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

void Mesh::set_shader_type(ShaderType shader_type)
{
	this->shader_type = shader_type;
}

void Mesh::set_texture_enabled(bool texture_enabled)
{
	this->texture_enabled = texture_enabled;
}

bool Mesh::is_texture_enabled()
{
	return this->texture_enabled;
}
