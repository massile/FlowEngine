#pragma once

#include "Mesh.h"

namespace FlowEngine { namespace Graphics {

    class Scene
    {
    private:
        std::vector<Mesh*> mMeshes;

    public:
        Scene();
        ~Scene();

        void add(Mesh* mesh);
        void render(Renderer3D& renderer);
    };

}}
