#include "ShaderComponent.h"
#include "../../graphics/Camera.h"

void ShaderComponent::update(Camera &camera, Shader &shader)
{
    shader.use();
    shader.uniform("view", camera.getViewMatrix());
    shader.uniform("projection", m_projection);
    shader.uniform("viewPos", camera.getPosition());
}
