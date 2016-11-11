#pragma once

#include "../renderer2d.h"
#include "../renderable2d.h"

namespace FlowEngine { namespace Graphics {

    class Layer
    {
    protected:
        Renderer2D* mRenderer;
        std::vector<Renderable2D*> mRenderables;
        Shader* mShader;
        glm::mat4 mProjectionMatrix;
    public:
        Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix);
        virtual ~Layer();

        virtual Renderable2D* add(Renderable2D* renderable);
        virtual void render();

        inline const std::vector<Renderable2D*>& getRenderables() const { return mRenderables; }
        void setMask(const Mask* mask) const { mRenderer->setMask(mask); }
    };

}}
