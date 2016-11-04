#include "Object.h"
#include "../services/environment/Environment.h"

Object::Object(InputComponent *inputComponent,
               PhysicsComponent *physicsComponent,
               ShaderComponent *shaderComponent,
               GraphicsComponent *graphicsComponent)
        : m_input(inputComponent),
          m_physics(physicsComponent),
          m_shader(shaderComponent),
          m_graphics(graphicsComponent)
{}

void Object::update(Shader &shader, float dt)
{
    if(m_physics) m_physics->update(this);
    if(m_input) m_input->update(this, dt);
    if(m_shader) m_shader->update(this, &shader);
    if(m_graphics) m_graphics->update(this, Environment::getWorld(), Environment::getGraphics());
}

void Object::setVelocity(const glm::vec3 &velocity)
{
    m_velocity = velocity;
}

void Object::setVelocityLocal(const glm::vec3 &velocity)
{
    glm::vec3 right = normalize(cross(m_up, m_front));
    m_velocity = velocity.z * m_front + velocity.y * m_up + velocity.x * right;
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
