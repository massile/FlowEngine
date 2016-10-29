#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include "../services/ui/window/Window.h"
#include "../components/input/InputComponent.h"
#include "../components/physics/PhysicsComponent.h"
#include "../components/shader/ShaderComponent.h"

class Camera
{
private:
    glm::mat4 m_view;

    glm::vec3 m_position = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_front = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 m_velocity = glm::vec3(0.0f, 0.0f, 0.0f);

    GLfloat m_yaw = 90.0f;
    GLfloat m_pitch = 0.0f;

    InputComponent m_input;
    PhysicsComponent m_physics;
    ShaderComponent m_shader;
public:
    Camera(const glm::vec3& position);
    ~Camera();

    void translate(const glm::vec3& offset) { m_position += offset; }

    inline GLfloat getYaw() const { return m_yaw; }
    inline GLfloat getPitch() const { return m_pitch; }
    inline glm::vec3 getPosition() const { return m_position; }
    inline glm::vec3 getFront() const { return m_front; }
    inline glm::vec3 getVelocity() const { return m_velocity; }
    inline glm::mat4 getViewMatrix() const { return m_view; }

    inline void setFront(const glm::vec3& front) { m_front = front; }
    inline void setPitch(const GLfloat pitch)
    {
        if(pitch > 89.0f)
            m_pitch = 89.0f;
        else if(pitch < -89.0f)
            m_pitch = -89.0f;
        else
            m_pitch = pitch;
    }
    inline void setYaw(const GLfloat yaw) { m_yaw = yaw; }
    inline void setVelocity(const glm::vec3& velocity)
    {
        glm::vec3 right = normalize(cross(m_front, m_up));
        m_velocity = velocity.x * right + velocity.y * m_up + velocity.z * m_front;
    }
    void lookAt(const glm::vec3& target) { m_view = glm::lookAt(m_position, target, m_up);}

    void update(Shader& shader, float dt);
};
