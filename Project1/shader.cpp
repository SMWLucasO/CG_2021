#include "shader.h"

Shader::Shader(const std::string folder_name)
{
	this->init(folder_name);
}

// in case this one is used, init must be called manually.
Shader::Shader()
{

}

void Shader::init(std::string folder_name)
{
    char* vertexshader = glsl::readFile((folder_name + "vertexshader.vert").c_str());
    GLuint vsh_id = glsl::makeVertexShader(vertexshader);

    char* fragshader = glsl::readFile((folder_name + "fragmentshader.frag").c_str());
    GLuint fsh_id = glsl::makeFragmentShader(fragshader);

    program_id = glsl::makeShaderProgram(vsh_id, fsh_id);
}

GLuint Shader::get_id()
{
    return this->program_id;
}
