#pragma once

#include <GL/glew.h>
#include "texture.h"
#include "../api/API.h"

namespace FlowEngine { namespace Graphics {

    class FrameBuffer
    {
    private:
        struct {
            uint frameBuffer;
            uint renderBuffer;
        } mData;

        Texture* mTexture;

    public:
        FrameBuffer(int width, int height);
        ~FrameBuffer();

        void bind() const;
        void clean() const;

        inline Texture* getTexture() const { return mTexture; }
        inline int getWidth() const { return mTexture->getWidth(); }
        inline int getHeight() const { return mTexture->getHeight(); }
    };

}}
