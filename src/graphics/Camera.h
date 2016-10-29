#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include "Object.h"

class Camera : public Object
{
private:
    glm::mat4 m_view;

public:
    Camera(InputComponent *inputComponent, PhysicsComponent *physicsComponent, ShaderComponent *shaderComponent)
        : Object(inputComponent, physicsComponent, shaderComponent) {
        m_position = glm::vec3(0, 0, -5);
    }
    ~Camera() {}

    inline glm::mat4 getViewMatrix() const { return m_view; }
    void lookAt(const glm::vec3& target) { m_view = glm::lookAt(m_position, target, m_up); }
};
