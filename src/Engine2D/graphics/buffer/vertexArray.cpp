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

    void VertexArray::addBuffer(VertexBuffer* buffer, GLuint index)
    {
        bind();
        buffer->bind();

        API::enableVertexAttribute(index);
        API::setVertexAttributePointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

        buffer->unbind();
        unbind();

        mBuffers.push_back(buffer);
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
