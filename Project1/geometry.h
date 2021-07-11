#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <GL/glew.h>

#include "loaders/texture/texture.h"

enum class TextureType {
	DDS,
	BMP
};

struct Texture {
	GLuint texture_id;
};

class Geometry
{
protected:

	// The texture of this geometry.
	Texture texture = Texture();

	// The normals of this geometry.
	std::vector<glm::vec3> normals;

	// The UVs of this geometry.
	std::vector<glm::vec2> uvs;

	// The vertices of this geometry.
	std::vector<glm::vec3> vertices;

public:
	Geometry(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals);
	Geometry();
	
	/**
	* Set up the data which the mesh needs from this geometry.
	*
	* @param program_id the shader program to get the GLuint references from.
	* @param vao a GLuint& to which the vertices, normals and UVs of this geometry are bound.
	* @param vbo_vertices a GLuint& referring to the vertices of this geometry.
	* @param vbo_uvs a GLuint& referring to the UVs of this geometry.
	* @param vbo_normals a GLuint& referring to the normals of this geometry.
	* @param position_id a GLuint& which we can use to send the position of the object to the shader program.
	* @param normal_id a GLuint& which we can use to send a normal of the mesh to the shader program.
	* @param uv_id a GLuint&  which we can use to send a UV of the mesh to the shader program.
	*/
	void setup(GLuint program_id, GLuint& vao, GLuint& vbo_vertices, GLuint& vbo_uvs, GLuint& vbo_normals, GLuint& position_id, GLuint& normal_id, GLuint& uv_id);


	/**
	* Get the texture for this geometry.
	* 
	* @return Texture
	*/
	Texture get_texture();
	
	/**
	* Set the texture for this geometry.
	* 
	* @param texture the texture to be applied to this geometry.
	*/
	void set_texture(Texture texture);

	/**
	* Load the texture for this geometry.
	*
	* @param url the location to get the image from.
	* @param texture_type the (file)type of the texture, we only support BMP and DDS.
	*/
	void load_texture(std::string url, TextureType texture_type);

	/**
	* Get the normals of this geometry.
	*
	* @return std::vector<glm::vec3>
	*/
	std::vector<glm::vec3> get_normals();

	/**
	* Get the uvs of this geometry
	*
	* @return std::vector<glm::vec2>
	*/
	std::vector<glm::vec2> get_uvs();

	/**
	* Get the vertices of this geometry.
	*
	* @return std::vector<glm::vec3>
	*/
	std::vector<glm::vec3> get_vertices();

};

