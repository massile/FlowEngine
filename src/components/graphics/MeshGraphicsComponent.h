#pragma once

#include "GraphicsComponent.h"
#include "../../services/environment/world/World.h"

class MeshGraphicsComponent : public GraphicsComponent
{
public:
    MeshGraphicsComponent() {}
    virtual void update(Object *object, World* world, Graphics* graphics) override;
};