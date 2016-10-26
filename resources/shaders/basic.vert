#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;

out vec2 texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    texCoords = vec2(uv.x, 1.0 - uv.y);
	gl_Position = projection * view * model * vec4(position, 1.0);
}
