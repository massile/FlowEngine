#include "PhysicsComponent.h"
#include "../../graphics/Camera.h"

void PhysicsComponent::update(Camera &camera)
{
    glm::vec3 fadedVelocity = 0.9f * camera.getVelocity();
    camera.setVelocity(fadedVelocity);
    camera.translate(camera.getVelocity());
}
