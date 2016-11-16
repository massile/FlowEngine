#include "Layer3D.h"

namespace FlowEngine { namespace Graphics {

    Layer3D::Layer3D(Renderer3D* renderer, Scene *scene)
        : Layer(renderer), mScene(scene)
    {

    }

    Layer3D::~Layer3D()
    {
        delete mScene;
        delete mRenderer;
    }

    void Layer3D::render()
    {
        mScene->render(*mRenderer);
        mRenderer->flush();
    }

    bool Layer3D::onEvent(const Events::Event &event)
    {
        return false;
    }

}}
