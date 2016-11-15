#pragma once

#include "PostEffectPass.h"
#include "buffer/indexBuffer.h"
#include "buffer/vertexArray.h"
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
