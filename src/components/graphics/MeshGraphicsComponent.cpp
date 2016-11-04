#include "MeshGraphicsComponent.h"

void MeshGraphicsComponent::update(Object *object, World* world, Graphics* graphics)
{
    TextureMap* rocksTexture = world->getRocksTexture();
    Shader* shader = world->getMeshShader();

    rocksTexture->use(*shader);
    graphics->render(world->getRock());
}
