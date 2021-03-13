#include "Geometry.h"

Geometry::Geometry(Material material, glm::vec3 position)
{
	this->material = material;
	this->transformations = Transformations();
	this->position = position;

	// setup the buffers
	this->init_buffers(material.get_shader()->program_id);

	std::cout << "Created a geometry!" << std::endl;
}

Geometry::Geometry(Material material) : Geometry(material, glm::vec3(0.0, 0.0, 0.0))
{
}

Geometry::Geometry() : Geometry(BasicMaterial())
{
}

void Geometry::init_matrices(Camera& camera, float screen_width, float screen_height) {
	glm::mat4 model;
	glm::scale(model, this->transformations.scaling);

	// rotations
	glm::rotate(model, glm::radians(this->transformations.rotation_x), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::rotate(model, glm::radians(this->transformations.rotation_y), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::rotate(model, glm::radians(this->transformations.rotation_z), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::translate(model, this->transformations.translation);

	glm::mat4 view = glm::lookAt(
		camera.get_position(),  // eye
		glm::vec3(0.0, 0.0, 0.0),  // center
		glm::vec3(0.0, 1.0, 0.0));  // up

	glm::mat4 projection = glm::perspective(
		glm::radians(camera.get_fov()),
		1.0f * screen_width / screen_height, 0.1f,
		20.0f);

	this->material.set_model(model);
	this->material.set_view(view);
	this->material.set_projection(projection);
}

void Geometry::init_buffers(GLuint program_id) {
	
	// vbo for vertices
	glGenBuffers(1, &this->vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(glm::vec3), &this->vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// bind the vbo for the coloring or textures
	this->material.get_visual().bind_visual_vbo(program_id);

	glGenBuffers(1, &this->ibo_faces);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo_faces);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->vertices.size() * sizeof(glm::vec3), &this->faces[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	position_id = glGetAttribLocation(program_id, "position");
	this->material.get_visual().set_visual_id(glGetAttribLocation(program_id, "color")); // we may want to move away from 'color' sometime. Idk.

	glGenVertexArrays(1, &vertex_array_object);

	glBindVertexArray(vertex_array_object);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	this->material.get_visual().bind_visual_vao(program_id);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo_faces);

	glBindVertexArray(0);

	this->material.setup_uniforms(program_id);

	glUseProgram(program_id);

	this->material.fill_uniforms(program_id);
}

void Geometry::render(Camera &camera, float screen_width, float screen_height)
{
	GLuint program_id = this->material.get_shader()->program_id;

	glUseProgram(program_id);

	// setup matrices
	glm::mat4 model;
	glm::scale(model, this->transformations.scaling);

	// rotations
	glm::rotate(model, glm::radians(this->transformations.rotation_x), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::rotate(model, glm::radians(this->transformations.rotation_y), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::rotate(model, glm::radians(this->transformations.rotation_z), glm::vec3(0.0f, 0.0f, 1.0f));
	
	glm::translate(model, this->transformations.translation);

	glm::mat4 view = glm::lookAt(
		camera.get_position(),  // eye
		glm::vec3(0.0, 0.0, 0.0),  // center
		glm::vec3(0.0, 1.0, 0.0));  // up

	glm::mat4 projection = glm::perspective(
		glm::radians(camera.get_fov()),
		1.0f * screen_width / screen_height, 0.1f,
		20.0f);

	this->material.set_model(model);
	this->material.set_view(view);
	this->material.set_projection(projection);

	this->material.send_uniforms(program_id);
	
	glBindVertexArray(this->vertex_array_object);
	glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
	glBindVertexArray(0);
}

Transformations Geometry::get_transformations()
{
	return this->transformations;
}

void Geometry::set_transformations(Transformations transformations)
{
	this->transformations = transformations;
}

Material Geometry::get_material()
{
	return this->material;
}

void Geometry::set_material(Material material)
{
	this->material = material;
}

glm::vec3 Geometry::get_position()
{
	return this->position;
}

void Geometry::set_position(glm::vec3 position)
{
	this->position = position;
}
