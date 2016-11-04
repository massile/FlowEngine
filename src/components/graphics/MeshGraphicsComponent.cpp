#include "MeshGraphicsComponent.h"

void MeshGraphicsComponent::update(Object *object, Graphics* graphics)
{
    graphics->render(m_mesh);
}
