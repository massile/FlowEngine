#include "vertexBuffer.h"
#include "../../api/API.h"

namespace FlowEngine { namespace Graphics {

    VertexBuffer::VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount)
            : mComponentCount(componentCount), mBufferID(API::createBuffer())
    {
        bind();
        API::setBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
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

}}
