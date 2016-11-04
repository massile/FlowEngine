#pragma once

#include "GraphicsComponent.h"

class MeshGraphicsComponent : public GraphicsComponent
{
private:
    Mesh* m_mesh;
public:
    MeshGraphicsComponent(Mesh* mesh): m_mesh(mesh) {}
    virtual void update(Object *object, Graphics* graphics) override;
};