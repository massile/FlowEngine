#include "Camera.h"

Camera::Camera(const glm::vec3 &position, GLfloat windowRatio)
        : m_view(glm::lookAt(position, glm::vec3(0), glm::vec3(0, 1, 0))),
          m_projection(glm::perspective(45.0f, windowRatio, 0.1f, 100.0f))
{

}

Camera::~Camera()
{

}

void Camera::update(Shader &shader)
{
    shader.use();
    shader.uniform("view", m_view);
    shader.uniform("projection", m_projection);
}

