#pragma once

#include "PostEffectPass.h"
#include "buffer/indexBuffer.h"
#include <vector>

namespace FlowEngine { namespace Graphics {

    class PostEffect
    {
    private:
        std::vector<PostEffectPass*> mPasses;
    public:
        PostEffect();
        ~PostEffect();

        void render(FrameBuffer* src, FrameBuffer* dest, uint quad, IndexBuffer* ibo);

        void push(PostEffectPass* pass);
        void pop();
    };

}}
