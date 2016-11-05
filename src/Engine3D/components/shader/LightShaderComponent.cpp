#include "LightShaderComponent.h"
#include "../../graphics/Light.h"

void LightShaderComponent::update(Object* object, Shader* shader)
{
    Light* light = static_cast<Light*>(object);

    shader->use();
    shader->uniform("lightPos", light->getPosition());
}
