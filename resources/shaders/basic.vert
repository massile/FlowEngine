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

uniform mat4 model = mat4(1.0);
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    vertex.uv = vec2(uv.x, 1.0 - uv.y);

    mat3 mat = transpose(inverse(mat3(model)));
    vec3 T = normalize(mat * tangent);
    vec3 B = normalize(mat * bitangent);
    vec3 N = normalize(mat * normal);

    mat3 TBN = transpose(mat3(T, B, N));
    vertex.tangentLightPos = TBN * lightPos;
    vertex.tangentViewPos  = TBN * viewPos;
    vertex.tangentFragPos  = TBN * vec3(model * vec4(position, 1.0));

	gl_Position = projection * view * model * vec4(position, 1.0);
}
