#include "vertexArray.h"
#include "../../api/API.h"

namespace FlowEngine { namespace Graphics {

    VertexArray::VertexArray()
    {
        mArrayID = API::createVertexArray();
    }

    VertexArray::~VertexArray()
    {
        for (int i = 0; i < mBuffers.size(); i++)
            delete mBuffers[i];
    }

    void VertexArray::addBuffer(VertexBuffer* buffer)
    {
        mBuffers.push_back(buffer);

        bind();
        buffer->bind();

        for(BufferAttribute attribute : buffer->getAttributes()) {
            API::enableVertexAttribute(attribute.index);
            API::setVertexAttributePointer(attribute.index, attribute.componentCount, attribute.type,
                                           attribute.normalized, buffer->getAttributeStride(), attribute.offset);
        }

        buffer->unbind();
        unbind();
    }

    void VertexArray::bind() const
    {
        API::bindVertexArray(mArrayID);
    }

    void VertexArray::unbind() const
    {
        API::unbindVertexArrays();
    }

}}
