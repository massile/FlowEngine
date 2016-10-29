#include <iostream>
#include "Camera.h"
#include "../services/input/Input.h"

Camera::Camera(const vec3 &position, GLfloat windowRatio)
        : m_position(position),
          m_view(lookAt(position, vec3(0), vec3(0, 1, 0))),
          m_projection(perspective(45.0f, windowRatio, 0.1f, 100.0f))
{

}

Camera::~Camera()
{

}

void Camera::update(Shader &shader)
{
    m_translate = 0.9f*m_translate;
    m_position += m_translate;
    m_view = lookAt(m_position, m_position + m_front, m_up);

    shader.use();
    shader.uniform("view", m_view);
    shader.uniform("projection", m_projection);
    shader.uniform("viewPos", m_position);
}

void Camera::processInput(float dt)
{
    processKeyboardInput(dt);
    processCursorInput(dt);
}

void Camera::processKeyboardInput(float dt)
{
    GLfloat speed = 8.0f * dt;
    vec3 right = normalize(cross(m_front, m_up));

    IKeyboard* keyboard = Input::getKeyboard();
    if(keyboard->isKeyPressed('W'))
        m_translate = speed * m_front;
    if(keyboard->isKeyPressed('S'))
        m_translate = -speed * m_front;
    if(keyboard->isKeyPressed('D'))
        m_translate = speed * right;
    if(keyboard->isKeyPressed('A'))
        m_translate = -speed * right;
    if(keyboard->isKeyPressed(GLFW_KEY_SPACE))
        m_translate = speed * m_up;

}

void Camera::processCursorInput(float dt)
{
    vec2 offset = m_sensitivity * Input::getMouse()->getCursorPositionOffset();

    m_yaw   += dt * offset.x;
    m_pitch += dt * offset.y;

    if (m_pitch > 89.0f)
        m_pitch = 89.0f;
    if (m_pitch < -89.0f)
        m_pitch = -89.0f;

    vec3 front = vec3(
        cos(radians(m_yaw)) * cos(radians(m_pitch)),
        sin(radians(m_pitch)),
        sin(radians(m_yaw)) * cos(radians(m_pitch))
    );
    m_front = normalize(front);
}

