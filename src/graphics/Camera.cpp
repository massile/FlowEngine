#include <iostream>
#include "Camera.h"

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
    m_view = lookAt(m_position, m_position + m_front, m_up);

    shader.use();
    shader.uniform("view", m_view);
    shader.uniform("projection", m_projection);
}

void Camera::processInput(const Window &window, float dt)
{
    processKeyboardInput(window, dt);
    processCursorInput(window, dt);
}

void Camera::processKeyboardInput(const Window &window, float dt)
{
    GLfloat speed = 5.0f * dt;
    vec3 right = normalize(cross(m_front, m_up));

    if(window.isKeyPressed('W'))
        m_position += speed * m_front;
    if(window.isKeyPressed('S'))
        m_position -= speed * m_front;
    if(window.isKeyPressed('D'))
        m_position += speed * right;
    if(window.isKeyPressed('A'))
        m_position -= speed * right;
}

void Camera::processCursorInput(const Window &window, float dt)
{
    vec2 offset = m_sensitivity * window.getCursorPositionOffset();

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

