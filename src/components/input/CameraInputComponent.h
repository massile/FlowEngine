#pragma once

#include "InputComponent.h"

class CameraInputComponent : public InputComponent
{
public:
    void update(Object* object, float dt) override;
};