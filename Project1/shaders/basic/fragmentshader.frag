#version 430 core

uniform bool texture_enabled;

in vec2 UV;
uniform sampler2D texsampler;

void main()
{
    gl_FragColor = vec4(texture2D(texsampler, UV).rgb, 1.0);
}
