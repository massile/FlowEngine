#pragma once

#include "IRenderable.h"
#include "Renderer3d.h"
#include <string>

namespace FlowEngine { namespace Graphics {

    class Model : IRenderable<Renderer3D>
    {
    private:
        Mesh* mMesh;
        const std::string mFilename;
    public:
        Model(const std::string& filename);
        virtual ~Model() = default;

        void render(Renderer3D &renderer) const override;
        inline Mesh* getMesh() const { return mMesh; }
    };

}}
