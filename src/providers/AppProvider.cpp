#include "AppProvider.h"

void AppProvider::record()
{
    Environment::provide(new World(), new Graphics());
}
