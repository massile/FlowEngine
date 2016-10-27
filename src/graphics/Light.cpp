#include "Light.h"

Light::Light(const glm::vec3 &position)
        : m_position(position)
{

}

void Light::update(Shader &shader)
{
    shader.use();
    shader.uniform("lightPos", m_position);
}
