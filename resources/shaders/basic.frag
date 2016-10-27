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

float computeSpecular(float NdotL, vec3 lightDirection)
{
    float roughnessStrength = 0.5;
    float F0 = 2.0;

    vec3 viewDirection = normalize(viewPos - vertex.fragPosition);
    vec3 halfVector = normalize(lightDirection + viewDirection);
    float NdotH = max(dot(vertex.normal, halfVector), 0.0);
    float NdotV = max(dot(vertex.normal, viewDirection), 0.0);
    float VdotH = max(dot(viewDirection, halfVector), 0.0);
    float rSquare = roughnessStrength * roughnessStrength;

    float ratio = 2.0 * NdotH / VdotH;
    float attenuationView = ratio * NdotV;
    float attenuationLight = ratio * NdotL;
    float geoAtt = min(1.0, min(attenuationView, attenuationLight));

    // Beckmann distribution function
    float r1 = 1.0 / ( 4.0 * rSquare * pow(NdotH, 4.0));
    float r2 = (NdotH * NdotH - 1.0) / (rSquare * NdotH * NdotH);
    float roughness = r1 * exp(r2);

    // Schlick approximation
    float fresnel = (1.0 - F0) * pow(1.0 - VdotH, 5.0) + F0;
    return (fresnel * geoAtt * roughness) / (NdotV * NdotL * 3.14);
}

void main()
{
    float k = 0.2;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 lightDirection = normalize(lightPos - vertex.fragPosition);

    float NdotL = max(dot(vertex.normal, lightDirection), 0.0);

    float specular;
    if(NdotL > 0.0f)
        specular = computeSpecular(NdotL, lightDirection);
    else
        specular = 0.0f;

    vec3 spec = texture(tex, vertex.uv).xyz * lightColor * NdotL * (k + specular * (1.0 - k));
    vec3 diffuse = texture(tex, vertex.uv).xyz  * vec3(0.2f, 0.2f, 0.2f);

    gl_FragColor = vec4(spec + diffuse, 1.0);
}
