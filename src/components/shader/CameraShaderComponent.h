#pragma once

#include "ShaderComponent.h"

class CameraShaderComponent : public ShaderComponent
{
private:
    glm::mat4 m_projection = glm::perspective(45.0f, Ui::getWindow()->getAspectRatio(), 0.1f, 100.0f);

public:
    void update(Object* object, Shader* shader) override;
};