#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec3 normal;

out Vertex {
    vec2 uv;
    vec3 normal;
    vec3 fragPosition;
} vertex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vertex.uv = vec2(uv.x, 1.0 - uv.y);
    vertex.normal = normal;
    vertex.fragPosition = vec3(model * vec4(position, 1.0));
	gl_Position = projection * view * vec4(vertex.fragPosition, 1.0);
}
