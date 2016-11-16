#pragma once

#include <vector>
#include <GL/glew.h>

#include "VertexBuffer.h"

namespace FlowEngine { namespace Graphics {

    class VertexArray
    {
    private:
        GLuint mArrayID;
        std::vector<VertexBuffer*> mBuffers;
    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(VertexBuffer* buffer);
        void bind() const;
        void unbind() const;
    };

}}
