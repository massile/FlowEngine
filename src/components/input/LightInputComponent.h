#pragma once

#include "InputComponent.h"

class LightInputComponent : public InputComponent
{
public:
    void update(Object* object, float dt);
};