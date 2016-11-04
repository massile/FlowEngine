#include "Environment.h"

Graphics* Environment::m_graphics;
World* Environment::m_world;

void Environment::provide(World* world, Graphics *graphics)
{
    m_world = world;
    m_graphics = graphics;
}
