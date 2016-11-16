#pragma once

#include "../Renderer2d.h"
#include "../Renderable2d.h"
#include "../../events/IEventListener.h"
#include "Layer.h"

namespace FlowEngine { namespace Graphics {

    class Layer2D : public Layer<Renderer2D>
    {
    protected:
        std::vector<Renderable2D*> mRenderables;
        Shader* mShader;
        glm::mat4 mProjectionMatrix;

    public:
        Layer2D(Renderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix);
        virtual ~Layer2D();

        virtual void render() override;
        Renderable2D* add(Renderable2D* renderable);
        void setMask(const Mask* mask) const { mRenderer->setMask(mask); }

    private:
        virtual bool onEvent(const Events::Event &event) override;
    };

}}
