#pragma once

#include "GraphicsComponent.h"
#include "../../services/environment/world/World.h"

class MeshGraphicsComponent : public GraphicsComponent
{
public:
    MeshGraphicsComponent() {}
    virtual void update(Object *object, IWorld* world, Graphics* graphics) override;
};