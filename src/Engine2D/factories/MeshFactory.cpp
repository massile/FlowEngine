#include "MeshFactory.h"
#include "../graphics/batchRenderer2d.h"

namespace FlowEngine { namespace Graphics {

    VertexArray* MeshFactory::generateQuad(float x, float y, float width, float height)
    {
        VertexData quad[4];

        quad[0].position = {x, y, 0.0f};
        quad[0].uv = {0.0f, 1.0f};

        quad[1].position = {x + width, y, 0.0f};
        quad[1].uv = {1.0f, 1.0f};

        quad[2].position = {x + width, y + height, 0.0f};
        quad[2].uv = {1.0f, 0.0f};

        quad[3].position = {x, y + height, 0.0f};
        quad[3].uv = {0.0f, 0.0f};

        uint bufferID = API::createBuffer();
        VertexArray* vertexArray = new VertexArray;

        vertexArray->bind();
        API::bindBuffer(GL_ARRAY_BUFFER, bufferID);
        API::setBufferData(GL_ARRAY_BUFFER, RENDERER_SPRITE_SIZE, quad, GL_STATIC_DRAW);

        API::enableVertexAttribute(POSITION);
        API::enableVertexAttribute(UV);

        API::setVertexAttributePointer(POSITION, 3, GL_FLOAT, false, RENDERER_VERTEX_SIZE, offsetof(VertexData, position));
        API::setVertexAttributePointer(UV, 2, GL_FLOAT, false, RENDERER_VERTEX_SIZE, offsetof(VertexData, uv));
        API::unbindBuffers(GL_ARRAY_BUFFER);
        vertexArray->unbind();

        return vertexArray;
    }

}}
