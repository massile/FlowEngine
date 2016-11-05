#pragma once

#include "graphics/Graphics.h"
#include "world/IWorld.h"

class Environment
{
public:
    static Graphics* getGraphics() { return m_graphics; }
    static IWorld* getWorld() { return m_world; }

    static void provide(IWorld* world, Graphics* graphics);
private:
    static Graphics* m_graphics;
    static IWorld* m_world;
};