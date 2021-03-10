#version 430 core

// Uniform matrices
uniform mat4 mv;
uniform mat4 projection;
uniform vec3 light_pos;

// Per-vertex inputs
in vec3 position;
in vec3 normal;

out VS_OUT
{
   vec3 N;
   vec3 L;
   vec3 V;
} vs_out;

void main()
{
    // Calculate view-space coordinate
    vec4 P = mv * vec4(position, 1.0);

    // Calculate normal in view-space
    vs_out.N = mat3(mv) * normal;

    // Calculate light vector
    vs_out.L = light_pos - P.xyz;

    // Calculate view vector;
    vs_out.V = -P.xyz;

    // Calculate the clip-space position of each vertex
    gl_Position = projection * P;
}
