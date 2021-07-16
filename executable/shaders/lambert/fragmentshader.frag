#version 430 core

// Input from vertex shader
in VS_OUT
{
    vec3 N;
    vec3 L;
} fs_in;

uniform bool texture_enabled;

in vec2 UV;
uniform sampler2D texsampler;

// Material properties
uniform vec3 mat_ambient;
uniform vec3 mat_diffuse;

void main()
{
    // Normalize the incoming N, L and V vectors
    vec3 N = normalize(fs_in.N);
    vec3 L = normalize(fs_in.L);

    vec3 diffuse;
	if (texture_enabled) {
		diffuse = max(dot(N, L), 0.0) * texture2D(texsampler, UV).rgb;
	} else {
		diffuse = max(dot(N, L), 0.0) * mat_diffuse;
	}
	
    // Write final color to the framebuffer
    gl_FragColor = vec4(mat_ambient + diffuse, 1.0);
}
