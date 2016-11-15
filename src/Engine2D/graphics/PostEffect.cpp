#include "PostEffect.h"

namespace FlowEngine { namespace Graphics {

    PostEffect::PostEffect() {}
    PostEffect::~PostEffect() {}

    void PostEffect::render(FrameBuffer *src, FrameBuffer *dest, VertexArray* quad, IndexBuffer *ibo)
    {
        dest->bind();
        API::setActiveTexture(GL_TEXTURE0);
        src->getTexture()->bind();

        quad->bind();
        ibo->bind();

        for(PostEffectPass* pass: mPasses)
            pass->render(dest);

        ibo->unbind();
        API::unbindVertexArrays();
    }

    void PostEffect::push(PostEffectPass *pass)
    {
        mPasses.push_back(pass);
    }

    void PostEffect::pop()
    {
        mPasses.pop_back();
    }

}}
