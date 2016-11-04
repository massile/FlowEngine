#pragma once

#include "../../services/environment/graphics/Graphics.h"

class Object;
class GraphicsComponent
{
public:
    virtual void update(Object* object, Graphics* graphics) = 0;
};