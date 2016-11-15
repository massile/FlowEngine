#pragma once

#include "../renderer2d.h"
#include "../renderable2d.h"
#include "../../events/IEventListener.h"

namespace FlowEngine { namespace Graphics {

    class Layer : Events::IEventListener
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

    private:
        virtual bool onEvent(const Events::Event &event) override;

    public:

        inline const std::vector<Renderable2D*>& getRenderables() const { return mRenderables; }
        inline const Renderer2D* getRenderer() const { return mRenderer; }
        void setMask(const Mask* mask) const { mRenderer->setMask(mask); }
    };

}}
