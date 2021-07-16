#version 430 core

// Uniform matrices
uniform mat4 mv;
uniform mat4 projection;

// Per-vertex inputs
in vec3 position;
in vec3 normal;

in vec2 uv;
out vec2 UV;

void main()
{
    // Calculate view-space coordinate
    vec4 P = mv * vec4(position, 1.0);

	UV = uv;

    // Calculate the clip-space position of each vertex
    gl_Position = projection * P;
}
