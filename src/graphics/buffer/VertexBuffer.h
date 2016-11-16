#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "../../api/API.h"

namespace FlowEngine { namespace Graphics {

    enum ShaderIndex { POSITION, COLOR, UV, MASK_UV, TID, MID, NORMAL=COLOR };

    struct BufferAttribute
    {
        ShaderIndex index;
        uint componentCount;
        uint type;
        bool normalized;
        uint offset;
    };

    class VertexBuffer
    {
    private:
        uint mBufferID;
        uint mTarget, mUsage;
        uint mSize, mStride = 0;

        std::vector<BufferAttribute> mAttributes;
    public:
        VertexBuffer(uint target, uint usage);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;
        void resize(uint size);

        void setData(uint size, const void* data);

        template<typename T>
        void setAttribute(ShaderIndex index, uint count = 1, bool normalized = false);
        inline std::vector<BufferAttribute> getAttributes() { return mAttributes; }
        inline uint getAttributeStride() const { return mStride; }
    };

}}
