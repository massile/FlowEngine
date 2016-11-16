#include "IndexBuffer.h"

namespace FlowEngine { namespace Graphics {

    void IndexBuffer::bind() const
    {
        API::bindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
    }

    void IndexBuffer::unbind() const
    {
        API::unbindBuffers(GL_ELEMENT_ARRAY_BUFFER);
    }

}}
