#include "Environment.h"

Graphics* Environment::m_graphics;

void Environment::provide(Graphics *graphics)
{
    m_graphics = graphics;
}
