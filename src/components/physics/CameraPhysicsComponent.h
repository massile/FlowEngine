#pragma once

#include "PhysicsComponent.h"

class CameraPhysicsComponent : public PhysicsComponent
{
public:
    void update(Object* object) override;
};