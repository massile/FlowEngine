#include "Object.h"

Object::Object(InputComponent *inputComponent, PhysicsComponent *physicsComponent, ShaderComponent *shaderComponent)
        : m_input(inputComponent),
          m_physics(physicsComponent),
          m_shader(shaderComponent)
{}

void Object::update(Shader &shader, float dt)
{
    m_physics->update(this);
    m_input->update(this, dt);
    m_shader->update(this, &shader);
}

void Object::setVelocity(const glm::vec3 &velocity)
{
    glm::vec3 right = normalize(cross(m_front, m_up));
    m_velocity = velocity.x * right + velocity.y * m_up + velocity.z * m_front;
}

void Object::setYaw(const GLfloat yaw) { m_yaw = yaw; }

void Object::setFront(const glm::vec3 &front) { m_front = front; }

void Object::setPitch(const GLfloat pitch)
{
    m_pitch = pitch;
    if(m_pitch > 89.0f)
        m_pitch = 89.0f;
    else if(m_pitch < -89.0f)
        m_pitch = -89.0f;
}
