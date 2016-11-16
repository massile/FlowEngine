#include "VertexBuffer.h"
#include "../../api/API.h"
#include "../Renderable2d.h"

namespace FlowEngine { namespace Graphics {

    VertexBuffer::VertexBuffer(uint target, uint usage)
            : mTarget(target), mUsage(usage)
    {
        mBufferID = API::createBuffer();
    }

    VertexBuffer::~VertexBuffer()
    {
        API::freeBuffer(mBufferID);
    }

    void VertexBuffer::resize(uint size)
    {
        setData(size, nullptr);
    }

    void VertexBuffer::setData(uint size, const void *data)
    {
        bind();
        mSize = size;
        API::setBufferData(mTarget, size, data, mUsage);
        unbind();
    }

    void VertexBuffer::bind() const
    {
        API::bindBuffer(GL_ARRAY_BUFFER, mBufferID);
    }

    void VertexBuffer::unbind() const
    {
        API::unbindBuffers(GL_ARRAY_BUFFER);
    }

    template <> void VertexBuffer::setAttribute<glm::vec3>(ShaderIndex index, uint count, bool normalized)
    {
        mAttributes.push_back({index, 3*count, GL_FLOAT, normalized, mStride});
        mStride += 3*sizeof(float);
    }

    template <> void VertexBuffer::setAttribute<glm::vec2>(ShaderIndex index, uint count, bool normalized)
    {
        mAttributes.push_back({index, 2*count, GL_FLOAT, normalized, mStride});
        mStride += 2*sizeof(float);
    }

    template <> void VertexBuffer::setAttribute<float>(ShaderIndex index, uint count, bool normalized)
    {
        mAttributes.push_back({index, count, GL_FLOAT, normalized, mStride});
        mStride += sizeof(float);
    }

    template <> void VertexBuffer::setAttribute<uint>(ShaderIndex index, uint count, bool normalized)
    {
        mAttributes.push_back({index, count, GL_UNSIGNED_BYTE, normalized, mStride});
        mStride += sizeof(uint);
    }

}}
