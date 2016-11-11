#include "batchRenderer2d.h"
#include "../utils/math.h"

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

        glEnableVertexAttribArray(ShaderIndex::POSITION);
        glEnableVertexAttribArray(ShaderIndex::COLOR);
        glEnableVertexAttribArray(ShaderIndex::UV);
        glEnableVertexAttribArray(ShaderIndex::MASK_UV);
        glEnableVertexAttribArray(ShaderIndex::TID);
        glEnableVertexAttribArray(ShaderIndex::MID);

        glVertexAttribPointer(ShaderIndex::POSITION, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (GLvoid*)offsetof(VertexData, position));
        glVertexAttribPointer(ShaderIndex::COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (GLvoid*)offsetof(VertexData, color));
        glVertexAttribPointer(ShaderIndex::UV, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (GLvoid*)offsetof(VertexData, uv));
        glVertexAttribPointer(ShaderIndex::MASK_UV, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (GLvoid*)offsetof(VertexData, maskUv));
        glVertexAttribPointer(ShaderIndex::TID, 1, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (GLvoid*)offsetof(VertexData, tid));
        glVertexAttribPointer(ShaderIndex::MID, 1, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (GLvoid*)offsetof(VertexData, mid));
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


    float BatchRenderer2D::submitTexture(GLuint textureID)
    {
        float textureSlot;
        bool found = false;
        for (int i = 0; i < mTextureSlots.size(); i++) {
            if (mTextureSlots[i] == textureID) {
                textureSlot = i + 1;
                found = true;
                break;
            }
        }
        if (!found) {
            mTextureSlots.push_back(textureID);
            textureSlot = mTextureSlots.size();
            if (textureSlot >= RENDERER_MAX_TEXTURES) {
                end();
                flush();
                begin();
            }
        }

        return textureSlot;
    }


    float BatchRenderer2D::submitTexture(Texture *texture)
    {
        return submitTexture(texture->getId());
    }

    void BatchRenderer2D::submit(const Renderable2D* renderable)
    {
        const glm::vec3& pos = renderable->getPosition();
        const glm::vec2& size = renderable->getSize();
        const GLuint color = renderable->getColor();
        const std::vector<glm::vec2>& uvs = renderable->getUvs();
        const GLuint tid = renderable->getTId();
        const GLuint mid = mMask->texture->getId();

        float textureSlot = tid > 0 ? submitTexture(renderable->getTexture()) : 0.0f;
        float maskSlot = mid > 0 ? submitTexture(mMask->texture) : 0.0f;

        glm::mat4 maskTransform = mMask ? glm::inverse(mMask->transform) : glm::mat4(1.0f);

        mBuffer->position = (*mTransformationBack) * glm::vec4(pos, 1.0f);
        mBuffer->color = color;
        mBuffer->uv = uvs[0];
        mBuffer->maskUv = maskTransform * mBuffer->position;
        mBuffer->tid = textureSlot;
        mBuffer->mid = maskSlot;
        mBuffer++;

        mBuffer->position = (*mTransformationBack) * glm::vec4(pos.x, pos.y + size.y, pos.z, 1.0f);
        mBuffer->color = color;
        mBuffer->uv = uvs[1];
        mBuffer->maskUv = maskTransform * mBuffer->position;
        mBuffer->tid = textureSlot;
        mBuffer->mid = maskSlot;
        mBuffer++;

        mBuffer->position = (*mTransformationBack) * glm::vec4(pos.x + size.x, pos.y + size.y, pos.z, 1.0f);
        mBuffer->color = color;
        mBuffer->uv = uvs[2];
        mBuffer->maskUv = maskTransform * mBuffer->position;
        mBuffer->tid = textureSlot;
        mBuffer->mid = maskSlot;
        mBuffer++;

        mBuffer->position = (*mTransformationBack) * glm::vec4(pos.x + size.x, pos.y, pos.z, 1.0f);
        mBuffer->color = color;
        mBuffer->uv = uvs[3];
        mBuffer->maskUv = maskTransform * mBuffer->position;
        mBuffer->tid = textureSlot;
        mBuffer->mid = maskSlot;
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

        glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, nullptr);

        mIBO->unbind();
        glBindVertexArray(0);

        mIndexCount = 0;
    }

}}