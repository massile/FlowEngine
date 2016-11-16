#pragma once

#include <vector>
#include "IRenderer.h"
#include "Mesh.h"

namespace FlowEngine { namespace Graphics {

    class Renderer3D : public IRenderer<Mesh>
    {
    protected:
        std::vector<const Mesh*> mDrawQueue;
    };
}}
