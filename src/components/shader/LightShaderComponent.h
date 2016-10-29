#pragma once

#include "ShaderComponent.h"

class LightShaderComponent : public ShaderComponent
{
public:
    void update(Object* object, Shader* shader) override;
};