#include "PostEffect.h"

namespace FlowEngine { namespace Graphics {

    PostEffect::PostEffect() {}
    PostEffect::~PostEffect() {}

    void PostEffect::render(FrameBuffer *src, FrameBuffer *dest, GLuint quad, IndexBuffer *ibo)
    {
        dest->bind();
        glActiveTexture(GL_TEXTURE0);
        src->getTexture()->bind();

        glBindVertexArray(quad);
        ibo->bind();

        for(PostEffectPass* pass: mPasses)
            pass->render(dest);

        ibo->unbind();
        glBindVertexArray(0);
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
