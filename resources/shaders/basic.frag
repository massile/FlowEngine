#version 330

in Vertex {
    vec2 uv;
    vec3 normal;
    vec3 fragPosition;
} vertex;

out vec4 color;

uniform sampler2D tex;
uniform vec3 viewPos;
uniform vec3 lightPos;

void main()
{
    vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;

    vec3 lightDirection = normalize(lightPos - vertex.fragPosition);
    float diffuseStrength = max(dot(vertex.normal, lightDirection), 0.0);
    vec3 diffuse = diffuseStrength * lightColor;

    float specularStrength = 0.5f;
    vec3 viewDirection = normalize(viewPos - vertex.fragPosition);
    vec3 reflectDirection = reflect(-lightDirection, vertex.normal);
    float specularIntensity = pow(max(dot(viewDirection, reflectDirection), 0.0), 32);
    vec3 specular = specularStrength * specularIntensity * vec3(1.0, 1.0, 1.0);

	color = vec4((ambient + diffuse + specular) * vec3(texture(tex, vertex.uv)), 1.0);
}
