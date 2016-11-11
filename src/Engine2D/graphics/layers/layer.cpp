#include "layer.h"
#include "../batchRenderer2d.h"

namespace FlowEngine { namespace Graphics {

    Layer::Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix)
            : mRenderer(renderer), mShader(shader), mProjectionMatrix(projectionMatrix)
    {
        mShader->enable();
        mShader->uniform("pr_matrix", mProjectionMatrix);

        std::vector<int> texIds;
        for(int i=0; i<RENDERER_MAX_TEXTURES+1; i++)
            texIds.push_back(i);
        mShader->uniform("textures", texIds.data(), RENDERER_MAX_TEXTURES+1);
        mShader->disable();
    }

    Layer::~Layer()
    {
        delete mShader;
        delete mRenderer;

        for (int i = 0; i < mRenderables.size(); i++)
            delete mRenderables[i];
    }

    Renderable2D* Layer::add(Renderable2D* renderable)
    {
        mRenderables.push_back(renderable);
        return renderable;
    }

    void Layer::render()
    {
        mShader->enable();

        mRenderer->begin();
        for (const Renderable2D* renderable : mRenderables)
            renderable->submit(mRenderer);
        mRenderer->end();

        mRenderer->flush();
    }

}}
