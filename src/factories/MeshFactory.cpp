#include "MeshFactory.h"
#include "../graphics/batchRenderer2d.h"

namespace FlowEngine { namespace Graphics {

    VertexArray* MeshFactory::generateQuad(float x, float y, float width, float height)
    {
        Vertex2D quad[4];

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

    Mesh* MeshFactory::generateCube(float size)
    {
        using namespace glm;
        Vertex3D vertices[8];

        vertices[0].position = vec3(-size/2, -size/2,  size/2);
        vertices[1].position = vec3( size/2, -size/2,  size/2);
        vertices[2].position = vec3( size/2,  size/2,  size/2);
        vertices[3].position = vec3(-size/2,  size/2,  size/2);

        vertices[4].position = vec3(-size/2, -size/2, -size/2);
        vertices[5].position = vec3( size/2, -size/2, -size/2);
        vertices[6].position = vec3( size/2,  size/2, -size/2);
        vertices[7].position = vec3(-size/2,  size/2, -size/2);

        vertices[0].normal = vec3(-1, -1,  1);
        vertices[1].normal = vec3( 1, -1,  1);
        vertices[2].normal = vec3( 1,  1,  1);
        vertices[3].normal = vec3(-1,  1,  1);

        vertices[4].normal = vec3(-1, -1, -1);
        vertices[5].normal = vec3( 1, -1, -1);
        vertices[6].normal = vec3( 1,  1, -1);
        vertices[7].normal = vec3(-1,  1, -1);

        VertexBuffer buffer(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
        buffer.setData(8*sizeof(Vertex3D), vertices);
        buffer.setAttribute<glm::vec3>(POSITION);
        buffer.setAttribute<glm::vec3>(NORMAL);
        buffer.setAttribute<glm::vec2>(UV);

        VertexArray vertexArray;
        vertexArray.addBuffer(&buffer);

        std::vector<uint> indices = {
            0, 1, 2, 2, 3, 0, 3, 2, 6, 6, 7, 3, 7, 6, 5, 5, 4, 7,
            4, 0, 3, 3, 7, 4, 0, 1, 5, 5, 4, 0, 1, 5, 6, 6, 2, 1
        };

        return new Mesh(&vertexArray, new IndexBuffer(indices));
    }

}}
