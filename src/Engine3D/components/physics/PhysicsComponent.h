#pragma once

class Object;
class PhysicsComponent
{
public:
    virtual void update(Object* object) = 0;
};