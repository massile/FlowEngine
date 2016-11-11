#pragma once

#include <GL/glew.h>

namespace FlowEngine { namespace Graphics {

    class VertexBuffer
    {
    private:
        GLuint mBufferID;
        GLuint mComponentCount;
    public:
        VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount);

        void bind() const;
        void unbind() const;

        inline GLuint getComponentCount() const { return mComponentCount; }
    };

}}
