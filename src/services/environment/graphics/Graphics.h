#pragma once

#include "../../../graphics/Mesh.h"

class Graphics
{
public:
    virtual void render(Mesh* mesh) const;
};