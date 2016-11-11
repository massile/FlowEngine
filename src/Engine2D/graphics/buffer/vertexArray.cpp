#include "vertexArray.h"

namespace FlowEngine { namespace Graphics {

    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &mArrayID);
    }

    VertexArray::~VertexArray()
    {
        for (int i = 0; i < mBuffers.size(); i++)
            delete mBuffers[i];
    }

    void VertexArray::addBuffer(VertexBuffer* buffer, GLuint index)
    {
        bind();
        buffer->bind();

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

        buffer->unbind();
        unbind();

        mBuffers.push_back(buffer);
    }

    void VertexArray::bind() const
    {
        glBindVertexArray(mArrayID);
    }

    void VertexArray::unbind() const
    {
        glBindVertexArray(0);
    }

}}
