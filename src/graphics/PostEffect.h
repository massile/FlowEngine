#pragma once

#include "PostEffectPass.h"
#include "buffer/IndexBuffer.h"
#include "buffer/VertexArray.h"
#include <vector>

namespace FlowEngine { namespace Graphics {

    class PostEffect
    {
    private:
        std::vector<PostEffectPass*> mPasses;
    public:
        PostEffect();
        ~PostEffect();

        void render(FrameBuffer* src, FrameBuffer* dest, VertexArray* quad, IndexBuffer* ibo);

        void push(PostEffectPass* pass);
        void pop();
    };

}}
