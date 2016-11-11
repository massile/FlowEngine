#include "layer.h"

namespace FlowEngine { namespace Graphics {

    Layer::Layer(Renderer2D* renderer, Shader* shader, glm::mat4 projectionMatrix)
            : mRenderer(renderer), mShader(shader), mProjectionMatrix(projectionMatrix)
    {
        mShader->enable();
        mShader->uniform("pr_matrix", mProjectionMatrix);

        std::vector<int> texIds;
        for(int i=0; i<32; i++)
            texIds.push_back(i);
        mShader->uniform("textures", texIds.data(), 32);
        mShader->disable();
    }

    Layer::~Layer()
    {
        delete mShader;
        delete mRenderer;

        for (int i = 0; i < mRenderables.size(); i++)
            delete mRenderables[i];
    }

    void Layer::add(Renderable2D* renderable)
    {
        mRenderables.push_back(renderable);
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
