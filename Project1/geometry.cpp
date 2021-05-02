#include "geometry.h"


Geometry::Geometry(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals)
{
	this->vertices = vertices;
	this->normals = normals;
	this->uvs = uvs;
}

Geometry::Geometry()
{
	// in this  case, do nothing.
}

Texture Geometry::get_texture()
{
	return this->texture;
}

void Geometry::set_texture(Texture texture)
{
	this->texture = texture;
}

void Geometry::setup(GLuint program_id, GLuint& vao, GLuint& vbo_vertices, GLuint& vbo_uvs, GLuint &vbo_normals, GLuint& position_id, GLuint& normal_id, GLuint& uv_id)
{

	glGenBuffers(1, &vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(
		GL_ARRAY_BUFFER,
		vertices.size() * sizeof(glm::vec3),
		&this->vertices[0],
		GL_STATIC_DRAW
	);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo_normals);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
	glBufferData(
		GL_ARRAY_BUFFER,
		normals.size() * sizeof(glm::vec3),
		&normals[0],
		GL_STATIC_DRAW
	);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo_uvs);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
	glBufferData(
		GL_ARRAY_BUFFER,
		uvs.size() * sizeof(glm::vec2),
		&uvs[0],
		GL_STATIC_DRAW
	);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	normal_id = glGetAttribLocation(program_id, "normal");
	position_id = glGetAttribLocation(program_id, "position");
	uv_id = glGetAttribLocation(program_id, "uv");

	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);

	// Bind vertices to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind normals to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
	glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(normal_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind uvs to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
	glVertexAttribPointer(uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(uv_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Geometry::load_texture(std::string url, TextureType texture_type)
{
	switch (texture_type) {
		case TextureType::BMP:
			this->texture.texture_id = loadBMP(url.c_str());
			break;
		case TextureType::DDS:
			this->texture.texture_id = loadDDS(url.c_str());
			break;
	}
}

std::vector<glm::vec3> Geometry::get_normals()
{
	return this->vertices;
}

std::vector<glm::vec2> Geometry::get_uvs()
{
	return this->uvs;
}

std::vector<glm::vec3> Geometry::get_vertices()
{
	return this->vertices;
}
