#include "CameraShaderComponent.h"
#include "../../graphics/Camera.h"

void CameraShaderComponent::update(Object* object, Shader* shader)
{
    Camera* camera = static_cast<Camera*>(object);

    shader->use();
    shader->uniform("view", camera->getViewMatrix());
    shader->uniform("projection", m_projection);
    shader->uniform("viewPos", camera->getPosition());
}
