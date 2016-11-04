#pragma once

#include "../../services/environment/graphics/Graphics.h"
#include "../../services/environment/world/World.h"

class Object;
class GraphicsComponent
{
public:
    virtual void update(Object* object, World* world, Graphics* graphics) = 0;
};