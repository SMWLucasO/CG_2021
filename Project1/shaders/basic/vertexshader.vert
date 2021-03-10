#version 430 core

in vec3 position;
in vec4 color;

out vec4 vColor;

void main()
{
    gl_Position = vec3(position, 1.0);
    vColor = color;
}