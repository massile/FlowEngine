#include <GL/glew.h>
#include "API.h"

namespace FlowEngine {

    uint API::createVertexArray()
    {
        GLuint arrayID;
        glGenVertexArrays(1, &arrayID);
        return arrayID;
    }
    uint API::createBuffer()
    {
        GLuint bufferID;
        glGenBuffers(1, &bufferID);
        return bufferID;
    }
    uint API::createFrameBuffer()
    {
        GLuint frameBuffer;
        glGenFramebuffers(1, &frameBuffer);
        return frameBuffer;
    }
    uint API::createRenderBuffer()
    {
        GLuint renderBuffer;
        glGenRenderbuffers(1, &renderBuffer);
        return renderBuffer;
    }
    uint API::createTexture()
    {
        GLuint texture;
        glGenTextures(1, &texture);
        return texture;
    }

    void API::setActiveTexture(uint texture) { glActiveTexture(texture); }
    void API::setViewport(int x, int y, uint width, uint height) { glViewport(x, y, width, height); }
    void API::setClearColor(int r, int g, int b, int a) { glClearColor(r, g, b, a); }
    void API::setVertexAttributePointer(uint index, uint size, uint type, bool normalized, uint stride, uint offset)
    {
        glVertexAttribPointer(index, size, type, normalized, stride, (const GLvoid*)offset);
    }
    void API::setBufferData(uint target, uint size, const void *data, uint usage)
    {
        glBufferData(target, size, data, usage);
    }
    void API::setTextureData(uint target, uint width, uint height, uint internalFormat, uint format, uint type, const void* pixels)
    {
        glTexImage2D(target, 0, internalFormat, width, height, 0, format, type, pixels);
    }
    void API::setTextureParameter(uint target, uint filter, uint filterMode)
    {
        glTexParameteri(target, filter, filterMode);
    }

    void API::bindVertexArray(uint vertexArray) { glBindVertexArray(vertexArray); }
    void API::bindBuffer(uint target, uint buffer) { glBindBuffer(target, buffer); }
    void API::bindRenderBuffer(uint target, uint buffer) { glBindRenderbuffer(target, buffer); }
    void API::bindTexture(uint target, uint texture) { glBindTexture(target, texture); }
    void API::bindFrameBuffer(uint target, uint buffer) { glBindFramebuffer(target, buffer); }

    void API::unbindVertexArrays() { glBindVertexArray(0); }
    void API::unbindBuffers(uint target) { glBindBuffer(target, 0); }
    void API::unbindTextures(uint target) { glBindTexture(target, 0); }

    void API::enableVertexAttribute(uint index) { glEnableVertexAttribArray(index);}
    void API::clear(uint buffer) { glClear(buffer); }
    void API::drawElements(uint mode, uint count, uint type, const void* indices)
    {
        glDrawElements(mode, count, type, indices);
    }
    void API::renderBufferStorage(uint target, uint format, int width, int height)
    {
        glRenderbufferStorage(target, format, width, height);
    }
    void API::frameBufferTexture2D(uint target, uint attachment, uint attachmentTarget, uint attachmentID, int level)
    {
        glFramebufferTexture2D(target, attachment, attachmentTarget, attachmentID, level);
    }
    void API::frameBufferRenderBuffer(uint target, uint attachment, uint attachmentTarget, uint attachmentID)
    {
        glFramebufferRenderbuffer(target, attachment, attachmentTarget, attachmentID);
    }

    void API::freeVertexArray(uint array) { glDeleteVertexArrays(1, &array); }
    void API::freeBuffer(uint buffer) { glDeleteBuffers(1, &buffer); }
    void API::freeFrameBuffer(uint buffer) { glDeleteFramebuffers(1, &buffer); }
    void API::freeRenderBuffer(uint buffer) { glDeleteRenderbuffers(1, &buffer); }
    void API::freeTexture(uint textureID) { glDeleteTextures(1, &textureID); }

}
