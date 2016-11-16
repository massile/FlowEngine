#include "Layer2D.h"
#include "../BatchRenderer2d.h"

namespace FlowEngine { namespace Graphics {

    Layer2D::Layer2D(Renderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix)
            : Layer(renderer), mShader(shader), mProjectionMatrix(projectionMatrix)
    {
        mShader->enable();
        mShader->uniform("pr_matrix", mProjectionMatrix);

        std::vector<int> texIds;
        for(int i=0; i<Renderer2D::MAX_TEXTURES+1; i++)
            texIds.push_back(i);
        mShader->uniform("textures", texIds.data(), Renderer2D::MAX_TEXTURES+1);
        mShader->disable();
    }

    Layer2D::~Layer2D()
    {
        delete mShader;
        delete mRenderer;

        for (int i = 0; i < mRenderables.size(); i++)
            delete mRenderables[i];
    }

    bool Layer2D::onEvent(const Events::Event &event)
    {
        return false;
    }

    Renderable2D* Layer2D::add(Renderable2D* renderable)
    {
        mRenderables.push_back(renderable);
        return renderable;
    }

    void Layer2D::render()
    {
        mShader->enable();

        mRenderer->begin();
        for (Renderable2D* renderable : mRenderables)
            renderable->submit(mRenderer);
        mRenderer->end();

        mRenderer->flush();
        mShader->disable();
    }

}}
