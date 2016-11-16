#pragma once

#include "Shader.h"
#include "FrameBuffer.h"

namespace FlowEngine { namespace Graphics {

    class PostEffectPass
    {
    private:
        Shader* mShader;
    public:
        PostEffectPass(Shader* shader);
        ~PostEffectPass();

        void render(FrameBuffer* target);
    };

}}
