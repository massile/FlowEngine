#include "indexBuffer.h"
#include "../../api/API.h"

namespace FlowEngine { namespace Graphics {

    IndexBuffer::IndexBuffer(GLushort* data, GLsizei count)
            : mCount(count), mBufferID(API::createBuffer())
    {
        bind();
        API::setBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
        unbind();
    }

    IndexBuffer::IndexBuffer(GLuint *data, GLsizei count)
            : mCount(count), mBufferID(API::createBuffer())
    {
        bind();
        API::setBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
        unbind();
    }

    void IndexBuffer::bind() const
    {
        API::bindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
    }

    void IndexBuffer::unbind() const
    {
        API::unbindBuffers(GL_ELEMENT_ARRAY_BUFFER);
    }

}}
