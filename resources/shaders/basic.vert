#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec3 tangent;
layout (location = 4) in vec3 bitangent;

out Vertex {
    vec2 uv;
    vec3 tangentFragPos;
    vec3 tangentViewPos;
    vec3 tangentLightPos;
} vertex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    vertex.uv = vec2(uv.x, 1.0 - uv.y);

    vec3 T = normalize(tangent);
    vec3 B = normalize(bitangent);
    vec3 N = normalize(normal);

    mat3 TBN = transpose(mat3(T, B, N));
    vertex.tangentLightPos = TBN * lightPos;
    vertex.tangentViewPos  = TBN * viewPos;
    vertex.tangentFragPos  = TBN * position;

	gl_Position = projection * view * model * vec4(position, 1.0);
}
