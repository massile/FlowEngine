#include <glm/vec3.hpp>
#include "CameraPhysicsComponent.h"
#include "../../graphics/Camera.h"

void CameraPhysicsComponent::update(Object* object)
{
    Camera* camera = static_cast<Camera*>(object);
    camera->setVelocity(0.9f * camera->getVelocity());
}
