#pragma once

#include "graphics/Graphics.h"

class Environment
{
public:
    static Graphics* getGraphics() { return m_graphics; }
    static void provide(Graphics* graphics);
private:
    static Graphics* m_graphics;
};