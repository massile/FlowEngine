#include "batchRenderer2d.h"

namespace FlowEngine { namespace Graphics {

    BatchRenderer2D::BatchRenderer2D()
    {
        init();
    }

    BatchRenderer2D::~BatchRenderer2D()
    {
        delete mIBO;
        glDeleteBuffers(1, &mVBO);
    }

    void BatchRenderer2D::init()
    {
        glGenVertexArrays(1, &mVAO);
        glGenBuffers(1, &mVBO);

        glBindVertexArray(mVAO);
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

        glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
        glEnableVertexAttribArray(SHADER_COLOR_INDEX);
        glEnableVertexAttribArray(SHADER_UV_INDEX);
        glEnableVertexAttribArray(SHADER_TID_INDEX);

        glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::position));
        glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::color));
        glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::uv));
        glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::tid));
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        GLuint* indices = new GLuint[RENDERER_INDICES_SIZE];

        int offset = 0;
        for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
        {
            indices[i] = offset + 0;
            indices[i + 1] = offset + 1;
            indices[i + 2] = offset + 2;

            indices[i + 3] = offset + 2;
            indices[i + 4] = offset + 3;
            indices[i + 5] = offset + 0;

            offset += 4;
        }

        mIBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

        glBindVertexArray(0);
    }

    void BatchRenderer2D::begin()
    {
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        mBuffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    }

    void BatchRenderer2D::submit(const Renderable2D* renderable)
    {
        const glm::vec3& pos = renderable->getPosition();
        const glm::vec2& size = renderable->getSize();
        const GLuint color = renderable->getColor();
        const std::vector<glm::vec2>& uvs = renderable->getUvs();
        const GLuint tid = renderable->getTId();

        float ts = 0.0f;
        if (tid > 0) {
            bool found = false;
            for (int i = 0; i < mTextureSlots.size(); i++) {
                if (mTextureSlots[i] == tid) {
                    ts = i + 1;
                    found = true;
                    break;
                }
            }
            if (!found) {
                mTextureSlots.push_back(tid);
                ts = mTextureSlots.size();
                if (ts >= RENDERER_MAX_TEXTURES) {
                    end();
                    flush();
                    begin();
                }
            }
        }

        mBuffer->position = (*mTransformationBack) * glm::vec4(pos, 1.0f);
        mBuffer->color = color;
        mBuffer->uv = uvs[0];
        mBuffer->tid = ts;
        mBuffer++;

        mBuffer->position = (*mTransformationBack) * glm::vec4(pos.x, pos.y + size.y, pos.z, 1.0f);
        mBuffer->color = color;
        mBuffer->uv = uvs[1];
        mBuffer->tid = ts;
        mBuffer++;

        mBuffer->position = (*mTransformationBack) * glm::vec4(pos.x + size.x, pos.y + size.y, pos.z, 1.0f);
        mBuffer->color = color;
        mBuffer->uv = uvs[2];
        mBuffer->tid = ts;
        mBuffer++;

        mBuffer->position = (*mTransformationBack) * glm::vec4(pos.x + size.x, pos.y, pos.z, 1.0f);
        mBuffer->color = color;
        mBuffer->uv = uvs[3];
        mBuffer->tid = ts;
        mBuffer++;

        mIndexCount += 6;
    }

    void BatchRenderer2D::end()
    {
        glUnmapBuffer(GL_ARRAY_BUFFER);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void BatchRenderer2D::flush()
    {
        for(int i=0; i<mTextureSlots.size(); i++) {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, mTextureSlots[i]);
        }

        glBindVertexArray(mVAO);
        mIBO->bind();

        glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, NULL);

        mIBO->unbind();
        glBindVertexArray(0);

        mIndexCount = 0;
    }

}}