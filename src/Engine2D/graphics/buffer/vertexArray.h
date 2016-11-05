#pragma once

#include <vector>
#include <GL/glew.h>

#include "vertexBuffer.h"

namespace FlowEngine { namespace Graphics {
    class VertexArray
    {
    private:
        GLuint m_ArrayID;
        std::vector<VertexBuffer*> m_Buffers;
    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(VertexBuffer* buffer, GLuint index);
        void bind() const;
        void unbind() const;
    };
}}