#pragma once

#include <GL/glew.h>
#include <glm/vec3.hpp>
#include "../components/shader/ShaderComponent.h"
#include "../components/input/InputComponent.h"
#include "../components/physics/PhysicsComponent.h"

class Object
{
protected:
    glm::vec3 m_position = glm::vec3(0.0f, 0.0f, -1.0f);

    glm::vec3 m_front = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 m_velocity = glm::vec3(0.0f, 0.0f, 0.0f);

    GLfloat m_yaw = 90.0f;
    GLfloat m_pitch = 0.0f;

    InputComponent* m_input;
    PhysicsComponent* m_physics;
    ShaderComponent* m_shader;

public:
    Object(InputComponent* inputComponent, PhysicsComponent* physicsComponent, ShaderComponent* shaderComponent);
    virtual ~Object() {}

    void translate(const glm::vec3& offset) { m_position += offset; }

    inline GLfloat getYaw() const { return m_yaw; }
    inline GLfloat getPitch() const { return m_pitch; }
    inline glm::vec3 getPosition() const { return m_position; }
    inline glm::vec3 getFront() const { return m_front; }
    inline glm::vec3 getVelocity() const { return m_velocity; }

    void setFront(const glm::vec3& front);
    void setPitch(const GLfloat pitch);
    void setYaw(const GLfloat yaw);
    void setVelocityLocal(const glm::vec3 &velocity);
    void setVelocity(const glm::vec3 &velocity);

    void update(Shader& shader, float dt);
};