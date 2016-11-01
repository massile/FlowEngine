#version 330

in Vertex {
    vec2 uv;
    vec3 tangentFragPos;
    vec3 tangentViewPos;
    vec3 tangentLightPos;
} vertex;

out vec4 color;

uniform sampler2D diffuseMap;
uniform sampler2D normalMap;
uniform sampler2D specularMap;

float computeSpecular(float NdotL, vec3 lightDirection, vec3 normal)
{
    float roughnessStrength = 0.4;
    float F0 = 0.8;

    vec3 viewDirection = normalize(vertex.tangentViewPos - vertex.tangentFragPos);
    vec3 halfVector = normalize(lightDirection + viewDirection);
    float NdotH = max(dot(normal, halfVector), 0.0);
    float NdotV = max(dot(normal, viewDirection), 0.0);
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
    return max((fresnel * geoAtt * roughness) / (NdotV * NdotL * 3.14), 0.0);
}

void main()
{
    float k = 0.8;
    vec3 lightColor = vec3(1.0, 0.7, 0.5);
    vec3 lightDirection = normalize(vertex.tangentLightPos - vertex.tangentFragPos);
    vec3 normalM = texture(normalMap, vertex.uv).rgb;
    vec3 normal = normalize(2.0 * vec3(normalM.r, 1.0 - normalM.g, normalM.b) - 1.0);

    float NdotL = max(dot(normal, lightDirection), 0.0);

    float specular;
    if(NdotL > 0.0f)
        specular = computeSpecular(NdotL, lightDirection, normal);
    else
        specular = 0.0f;

    vec3 spec = lightColor * NdotL * texture(specularMap, vertex.uv).xyz * (k + specular * (1.0 - k));
    vec3 diffuse = lightColor * NdotL * texture(diffuseMap, vertex.uv).xyz  * vec3(1.0f, 1.0, 1.0);

    float distance = length(vertex.tangentLightPos - vertex.tangentFragPos);
    float attenuation = min(2.0 * exp(-distance * 0.2), 1.0);

    vec3 color = attenuation*(spec + diffuse) + vec3(0.2, 0.2, 0.4) *  texture(specularMap, vertex.uv).xyz  * texture(diffuseMap, vertex.uv).xyz * exp(-0.1*distance);
    color = pow(color, vec3(1.0/2.2));
    gl_FragColor = vec4(color, 1.0);
}
