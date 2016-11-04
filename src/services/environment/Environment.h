#pragma once

#include "graphics/Graphics.h"
#include "world/World.h"

class Environment
{
public:
    static Graphics* getGraphics() { return m_graphics; }
    static World* getWorld() { return m_world; }

    static void provide(World* world, Graphics* graphics);
private:
    static Graphics* m_graphics;
    static World* m_world;
};