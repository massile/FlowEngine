#include "MeshGraphicsComponent.h"

void MeshGraphicsComponent::update(Object *object, IWorld* world, Graphics* graphics)
{
    TextureMap* rocksTexture = world->getTexture("rocks");
    Shader* shader = world->getShader("shader");

    rocksTexture->use(*shader);
    graphics->render(world->getMesh("rock"));
}
