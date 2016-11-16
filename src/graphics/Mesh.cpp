#include "Mesh.h"

namespace FlowEngine { namespace Graphics {

    Mesh::Mesh(VertexArray *vertexArray, IndexBuffer *indexBuffer)
            : mVertexArray(vertexArray), mIndexBuffer(indexBuffer) {}

    Mesh::~Mesh()
    {
        delete mVertexArray;
        delete mIndexBuffer;
    }

    void Mesh::render(Renderer3D &renderer) const
    {
        mVertexArray->bind();
        mIndexBuffer->bind();
        API::drawElements(GL_TRIANGLES, mIndexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
        mIndexBuffer->unbind();
        mVertexArray->unbind();
    }

}}
