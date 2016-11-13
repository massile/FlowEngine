#pragma once

#include "shader.h"
#include "frameBuffer.h"

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
