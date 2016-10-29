#include "Light.h"
#include "../services/input/keyboard/IKeyboard.h"
#include "../services/input/Input.h"

Light::Light(const glm::vec3 &position)
        : m_position(position)
{

}

void Light::update(Shader &shader)
{
    shader.use();
    shader.uniform("lightPos", m_position);
}

void Light::processInput(float dt)
{
    using namespace glm;
    GLfloat speed = 50.0f * dt;

    IKeyboard* keyboard = Input::getKeyboard();
    if(keyboard->isKeyPressed('I'))
        m_position += speed * vec3(0, 1, 0);
    if(keyboard->isKeyPressed('K'))
        m_position -= speed * vec3(0, 1, 0);
    if(keyboard->isKeyPressed('L'))
        m_position -= speed * vec3(1, 0, 0);
    if(keyboard->isKeyPressed('J'))
        m_position += speed * vec3(1, 0, 0);
    if(keyboard->isKeyPressed('O'))
        m_position += speed * vec3(0, 0, 1);
    if(keyboard->isKeyPressed('U'))
        m_position -= speed * vec3(0, 0, 1);
}
