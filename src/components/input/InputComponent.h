#pragma once

#include <GL/glew.h>

class Object;
class InputComponent
{
public:
    virtual void update(Object* object, float dt) = 0;
};