#pragma once

#include "Object.h"

class Light : public Object
{
public:
    Light(InputComponent *inputComponent, PhysicsComponent *physicsComponent, ShaderComponent *shaderComponent)
            : Object(inputComponent, physicsComponent, shaderComponent) {}
};
