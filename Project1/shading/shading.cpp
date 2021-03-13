#include "shading.h"

// declare our shader programs
ShaderProgram Phong, Lambert, Basic;

void init_shader(ShaderProgram& shader, const char* vertexshader_name, const char* fragshader_name)
{
    char* vertexshader = glsl::readFile(vertexshader_name);
    shader.vsh_id = glsl::makeVertexShader(vertexshader);

    char* fragshader = glsl::readFile(fragshader_name);
    shader.fsh_id = glsl::makeFragmentShader(fragshader);

    shader.program_id = glsl::makeShaderProgram(shader.vsh_id, shader.fsh_id);
}