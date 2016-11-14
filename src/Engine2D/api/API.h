#pragma once

typedef unsigned int uint;

namespace FlowEngine {
    namespace API
    {
        uint createVertexArray();
        uint createBuffer();
        uint createFrameBuffer();
        uint createRenderBuffer();
        uint createTexture();

        void setBufferData(uint target, uint size, const void* data, uint usage);
        void setTextureData(uint target, uint width, uint height, uint internalFormat, uint format, uint type, const void* pixels);
        void setActiveTexture(uint texture);
        void setViewport(int x, int y, uint width, uint height);
        void setClearColor(int r, int g, int b, int a);
        void setVertexAttributePointer(uint index, uint size, uint type, bool normalized, uint stride, uint offset);
        void setTextureParameter(uint target, uint filter, uint filterMode);

        void bindVertexArray(uint vertexArray);
        void bindBuffer(uint target, uint buffer);
        void bindRenderBuffer(uint target, uint buffer);
        void bindTexture(uint target, uint texture);
        void bindFrameBuffer(uint target, uint buffer);

        void unbindVertexArrays();
        void unbindBuffers(uint target);
        void unbindTextures(uint target);

        void enableVertexAttribute(uint index);
        void clear(uint buffer);
        void drawElements(uint mode, uint count, uint type, const void* indices);
        void renderBufferStorage(uint target, uint format, int width, int height);
        void frameBufferTexture2D(uint target, uint attachement, uint attachmentTarget, uint attachmentID, int level);
        void frameBufferRenderBuffer(uint target, uint attachment, uint attachmentTarget, uint attachmentID);

        void freeVertexArray(uint array);
        void freeBuffer(uint buffer);
        void freeFrameBuffer(uint buffer);
        void freeRenderBuffer(uint buffer);
        void freeTexture(uint textureID);
    }
}
