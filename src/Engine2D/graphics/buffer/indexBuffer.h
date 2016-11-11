#pragma once

#include <GL/glew.h>

namespace FlowEngine { namespace Graphics {

    class IndexBuffer
    {
    private:
        GLuint mBufferID;
        GLuint mCount;
    public:
        IndexBuffer(GLushort* data, GLsizei count);
        IndexBuffer(GLuint* data, GLsizei count);

        void bind() const;
        void unbind() const;

        inline GLuint getCount() const { return mCount; }
    };

}}
