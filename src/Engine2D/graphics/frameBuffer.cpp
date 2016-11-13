#include "frameBuffer.h"

namespace FlowEngine { namespace Graphics {

    FrameBuffer::FrameBuffer(int width, int height)
        : mTexture(new Texture(width, height))
    {
        glGenRenderbuffers(1, &mData.renderBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, mData.renderBuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);

        glGenFramebuffers(1, &mData.frameBuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, mData.frameBuffer);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexture->getId(), 0);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, mData.renderBuffer);
    }

    FrameBuffer::~FrameBuffer()
    {
        glDeleteFramebuffers(1, &mData.frameBuffer);
        glDeleteRenderbuffers(1, &mData.renderBuffer);
    }

    void FrameBuffer::bind() const
    {
        glBindFramebuffer(GL_FRAMEBUFFER, mData.frameBuffer);
        glViewport(0, 0, mTexture->getWidth(), mTexture->getHeight());
    }

    void FrameBuffer::clean() const
    {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

}}
