#pragma once

#include <GL/glew.h>
#include <vector>
#include "../../api/API.h"

namespace FlowEngine { namespace Graphics {

    class IndexBuffer
    {
    private:
        GLuint mBufferID;
        GLuint mCount;
    public:
        template <typename T>
        IndexBuffer(const std::vector<T>& indices) : mBufferID(API::createBuffer()), mCount(indices.size())
        {
            bind();
            API::setBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(T), indices.data(), GL_STATIC_DRAW);
            unbind();
        }

        void bind() const;
        void unbind() const;

        inline GLuint getCount() const { return mCount; }
    };

}}
