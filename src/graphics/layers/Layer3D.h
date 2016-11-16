#pragma once

#include "Layer2D.h"
#include "../renderer3d.h"
#include "../Scene.h"

namespace FlowEngine { namespace Graphics {

    class Layer3D : public Layer<Renderer3D>
    {
    protected:
        Scene* mScene;

    public:
        Layer3D(Renderer3D* renderer, Scene* scene);
        ~Layer3D();

        inline Scene* getScene() const { return mScene; }
        virtual void render() override;
    };

}}
