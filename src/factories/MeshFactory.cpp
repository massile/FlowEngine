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

        VertexBuffer buffer(GL_ARRAY_BUFFER, GL_DYNAMIC_DRAW);
        buffer.setData(Renderer2D::SPRITE_BYTE_SIZE, quad);
        buffer.setAttribute<glm::vec3>(POSITION);
        buffer.setAttribute<uint>(COLOR, 4, true);
        buffer.setAttribute<glm::vec2>(UV);
        buffer.setAttribute<glm::vec2>(MASK_UV);
        buffer.setAttribute<float>(TID);
        buffer.setAttribute<float>(MID);

        VertexArray* vertexArray = new VertexArray;
        vertexArray->addBuffer(&buffer);

        return vertexArray;
    }

}}
