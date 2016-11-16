#pragma once

#include "buffer/VertexArray.h"
#include "buffer/IndexBuffer.h"
#include "IRenderable.h"

namespace FlowEngine { namespace Graphics {

    class Renderer3D;
    class Mesh : public IRenderable<Renderer3D>
    {
    private:
        VertexArray* mVertexArray;
        IndexBuffer* mIndexBuffer;
    public:
        Mesh(VertexArray* vertexArray, IndexBuffer* indexBuffer);
        ~Mesh();

        void render(Renderer3D& renderer) const override;
    };

}}
