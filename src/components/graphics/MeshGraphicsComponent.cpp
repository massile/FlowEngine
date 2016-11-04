#include "MeshGraphicsComponent.h"
#include "../../services/environment/Environment.h"

void MeshGraphicsComponent::update(Object *object, Graphics* graphics)
{
    graphics->render(Environment::getWorld()->getRock());
}
