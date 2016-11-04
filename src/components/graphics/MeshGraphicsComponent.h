#pragma once

#include "GraphicsComponent.h"

class MeshGraphicsComponent : public GraphicsComponent
{
public:
    MeshGraphicsComponent() {}
    virtual void update(Object *object, Graphics* graphics) override;
};