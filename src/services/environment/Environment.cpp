#include "Environment.h"

Graphics* Environment::m_graphics;
IWorld* Environment::m_world;

void Environment::provide(IWorld* world, Graphics *graphics)
{
    m_world = world;
    m_graphics = graphics;
}
