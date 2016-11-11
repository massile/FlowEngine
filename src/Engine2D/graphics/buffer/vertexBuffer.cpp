#include "vertexBuffer.h"

namespace FlowEngine { namespace Graphics {

    VertexBuffer::VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount)
            : mComponentCount(componentCount)
    {
        glGenBuffers(1, &mBufferID);
        glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
    }

    void VertexBuffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}}
