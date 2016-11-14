#include "batchRenderer2d.h"
#include "../utils/math.h"
#include "../factories/MeshFactory.h"

namespace FlowEngine { namespace Graphics {

    BatchRenderer2D::BatchRenderer2D(const glm::vec2& screenSize)
        : mScreenSize(screenSize),
          mFrameBuffer(new FrameBuffer(screenSize.x, screenSize.y)),
          mScreenQuad(MeshFactory::generateQuad(0, 0, mScreenSize.x, mScreenSize.y)),
          mFramebufferShader(new Shader("resources/shaders/framebuffer.vert", "resources/shaders/framebuffer.frag")),
          mPostEffect(new PostEffect),
          mPostEffectBuffer(new FrameBuffer(screenSize.x, screenSize.y))
    {
        mVAO = API::createVertexArray();
        mVBO = API::createBuffer();
        API::bindVertexArray(mVAO);
        API::bindBuffer(GL_ARRAY_BUFFER, mVBO);
        API::setBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW);

        for(int i=ShaderIndex::FIRST; i<=ShaderIndex::LAST; i++)
            API::enableVertexAttribute(i);
        API::setVertexAttributePointer(POSITION, 3, GL_FLOAT, false, RENDERER_VERTEX_SIZE, offsetof(VertexData, position));
        API::setVertexAttributePointer(COLOR, 4, GL_UNSIGNED_BYTE, true, RENDERER_VERTEX_SIZE, offsetof(VertexData, color));
        API::setVertexAttributePointer(UV, 2, GL_FLOAT, false, RENDERER_VERTEX_SIZE, offsetof(VertexData, uv));
        API::setVertexAttributePointer(MASK_UV, 2, GL_FLOAT, false, RENDERER_VERTEX_SIZE, offsetof(VertexData, maskUv));
        API::setVertexAttributePointer(TID, 1, GL_FLOAT, false, RENDERER_VERTEX_SIZE, offsetof(VertexData, tid));
        API::setVertexAttributePointer(MID, 1, GL_FLOAT, false, RENDERER_VERTEX_SIZE, offsetof(VertexData, mid));
        API::unbindBuffers(GL_ARRAY_BUFFER);

        GLuint* indices = new GLuint[RENDERER_INDICES_SIZE];
        for(int i=0, offset=0; i < RENDERER_INDICES_SIZE; i+=6, offset+=4)
        {
            indices[i] = offset;
            indices[i+1] = offset + 1;
            indices[i+2] = offset + 2;
            indices[i+3] = offset + 2;
            indices[i+4] = offset + 3;
            indices[i+5] = offset;
        }

        mIBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
        API::unbindVertexArrays();

        mFramebufferShader->enable();
        mFramebufferShader->uniform("tex", 0);
        mFramebufferShader->uniform("pr_matrix", glm::ortho(0.0f, mScreenSize.x, mScreenSize.y, 0.0f, -1.0f, 1.0f));
        mFramebufferShader->disable();
    }

    BatchRenderer2D::~BatchRenderer2D()
    {
        delete mIBO;
        API::freeVertexArray(mVAO);
        API::freeBuffer(mVBO);
    }

    void BatchRenderer2D::begin()
    {
        mPostEffectBuffer->bind();
        mPostEffectBuffer->clean();

        mFrameBuffer->bind();
        mFrameBuffer->clean();

        API::bindBuffer(GL_ARRAY_BUFFER, mVBO);
        mBuffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    }

    float BatchRenderer2D::submitTexture(uint textureID)
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
        API::unbindBuffers(GL_ARRAY_BUFFER);
    }

    void BatchRenderer2D::flush()
    {
        for(int i=0; i<mTextureSlots.size(); i++) {
            API::setActiveTexture(GL_TEXTURE0 + i);
            API::bindTexture(GL_TEXTURE_2D, mTextureSlots[i]);
        }

        API::bindVertexArray(mVAO);
        mIBO->bind();
        API::drawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, nullptr);
        mIBO->unbind();
        API::unbindVertexArrays();

        mIndexCount = 0;
        mTextureSlots.clear();

        mPostEffect->render(mFrameBuffer, mPostEffectBuffer, mScreenQuad, mIBO);

        API::bindFrameBuffer(GL_FRAMEBUFFER, 0);
        API::setViewport(0, 0, mScreenSize.x, mScreenSize.y);

        API::setActiveTexture(GL_TEXTURE0);
        mPostEffectBuffer->getTexture()->bind();

        mFramebufferShader->enable();
        API::bindVertexArray(mScreenQuad);
        mIBO->bind();
        API::drawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        mIBO->unbind();
        API::bindVertexArray(0);
        mFramebufferShader->disable();
    }

}}