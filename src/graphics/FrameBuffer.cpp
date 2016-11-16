#include "FrameBuffer.h"

namespace FlowEngine { namespace Graphics {

    FrameBuffer::FrameBuffer(int width, int height)
        : mTexture(new Texture(width, height))
    {
        mData.renderBuffer = API::createRenderBuffer();
        API::bindRenderBuffer(GL_RENDERBUFFER, mData.renderBuffer);
        API::renderBufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);

        mData.frameBuffer = API::createFrameBuffer();
        API::bindFrameBuffer(GL_FRAMEBUFFER, mData.frameBuffer);
        API::frameBufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexture->getId(), 0);
        API::frameBufferRenderBuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, mData.renderBuffer);
    }

    FrameBuffer::~FrameBuffer()
    {
        API::freeFrameBuffer(mData.frameBuffer);
        API::freeRenderBuffer(mData.renderBuffer);
    }

    void FrameBuffer::bind() const
    {
        API::bindFrameBuffer(GL_FRAMEBUFFER, mData.frameBuffer);
        API::setViewport(0, 0, mTexture->getWidth(), mTexture->getHeight());
    }

    void FrameBuffer::clean() const
    {
        API::setClearColor(0, 0, 0, 1);
        API::clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

}}
