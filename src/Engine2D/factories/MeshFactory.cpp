#include "MeshFactory.h"
#include "../graphics/batchRenderer2d.h"

namespace FlowEngine { namespace Graphics {

    GLuint MeshFactory::generateQuad(float x, float y, float width, float height)
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

        GLuint bufferID, meshID;
        glGenVertexArrays(1, &meshID);
        glGenBuffers(1, &bufferID);

        glBindVertexArray(meshID);
        glBindBuffer(GL_ARRAY_BUFFER, bufferID);
        glBufferData(GL_ARRAY_BUFFER, RENDERER_SPRITE_SIZE, quad, GL_STATIC_DRAW);

        glEnableVertexAttribArray(ShaderIndex::POSITION);
        glEnableVertexAttribArray(ShaderIndex::UV);

        glVertexAttribPointer(ShaderIndex::POSITION, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (GLvoid*)offsetof(VertexData, position));
        glVertexAttribPointer(ShaderIndex::UV, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (GLvoid*)offsetof(VertexData, uv));
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        return meshID;
    }

}}
