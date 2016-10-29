#include "Camera.h"

Camera::Camera(const glm::vec3& position)
        : m_position(position),
          m_view(glm::lookAt(m_position, glm::vec3(0), m_up)) {}

Camera::~Camera() {}

void Camera::update(Shader &shader, float dt)
{
    m_input.update(*this, dt);
    m_physics.update(*this);
    m_shader.update(*this, shader);
}