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

void Light::processInput(IWindow* window, float dt)
{
    using namespace glm;

    GLfloat speed = 50.0f * dt;
    if(window->isKeyPressed('I'))
        m_position += speed * vec3(0, 1, 0);
    if(window->isKeyPressed('K'))
        m_position -= speed * vec3(0, 1, 0);
    if(window->isKeyPressed('L'))
        m_position -= speed * vec3(1, 0, 0);
    if(window->isKeyPressed('J'))
        m_position += speed * vec3(1, 0, 0);
    if(window->isKeyPressed('O'))
        m_position += speed * vec3(0, 0, 1);
    if(window->isKeyPressed('U'))
        m_position -= speed * vec3(0, 0, 1);
}
