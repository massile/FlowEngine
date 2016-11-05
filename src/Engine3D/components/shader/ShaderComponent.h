#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "../../services/ui/Ui.h"
#include "../../graphics/Shader.h"

class Object;
class ShaderComponent
{
public:
    virtual void update(Object* object, Shader* shader) = 0;
};