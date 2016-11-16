#pragma once

#include "buffer/vertexArray.h"
#include "buffer/indexBuffer.h"

namespace FlowEngine { namespace Graphics {

    class Renderer3D;
    class Mesh
    {
    private:
        VertexArray* mVertexArray;
        IndexBuffer* mIndexBuffer;
    public:
        Mesh(VertexArray* vertexArray, IndexBuffer* indexBuffer);
        ~Mesh();

        void render(Renderer3D& renderer) const;
    };

}}
