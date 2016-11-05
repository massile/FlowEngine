#pragma once

#include "../../services/environment/graphics/Graphics.h"
#include "../../services/environment/world/IWorld.h"

class Object;
class GraphicsComponent
{
public:
    virtual void update(Object* object, IWorld* world, Graphics* graphics) = 0;
};