#pragma once

#include <GL/glew.h>
#include "texture.h"

namespace FlowEngine { namespace Graphics {

    class FrameBuffer
    {
    private:
        struct {
            GLuint frameBuffer;
            GLuint renderBuffer;
        } mData;

        Texture* mTexture;

    public:
        FrameBuffer(int width, int height);
        ~FrameBuffer();

        void bind() const;
        void clean() const;

        inline Texture* getTexture() const { return mTexture; }
    };

}}
