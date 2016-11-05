#pragma once

#include <GL/glew.h>

namespace FlowEngine { namespace Graphics {
    class VertexBuffer
    {
    private:
        GLuint m_BufferID;
        GLuint m_ComponentCount;
    public:
        VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount);

        void bind() const;
        void unbind() const;

        inline GLuint getComponentCount() const { return m_ComponentCount; }
    };
}}