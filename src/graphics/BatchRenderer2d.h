#pragma once

#include "Renderer2d.h"
#include "buffer/IndexBuffer.h"
#include "Renderable2d.h"
#include "FrameBuffer.h"
#include "PostEffect.h"
#include "Vertex.h"

namespace FlowEngine { namespace Graphics {

    class BatchRenderer2D : public Renderer2D
    {
    private:
        VertexArray* mVAO = new VertexArray;
        VertexArray* mScreenQuad;

        VertexBuffer* mVBO = new VertexBuffer(GL_ARRAY_BUFFER, GL_DYNAMIC_DRAW);
        IndexBuffer* mIBO;
        uint mIndexCount;
        Vertex2D* mBuffer;
        std::vector<uint> mTextureSlots;

        Shader* mFramebufferShader = new Shader("resources/shaders/framebuffer.vert", "resources/shaders/framebuffer.frag");
        FrameBuffer* mFrameBuffer;
        FrameBuffer* mPostEffectBuffer;

        PostEffect* mPostEffect = new PostEffect;

        glm::vec2 mScreenSize;
    public:
        BatchRenderer2D(const glm::vec2& screenSize);
        ~BatchRenderer2D();

        void begin() override;
        void submit(const Renderable2D* renderable) override;
        void end() override;
        void flush() override;

        inline void addPostEffectPass(PostEffectPass* pass) { mPostEffect->push(pass); }

    private:
        float submitTexture(GLuint textureID);
        float submitTexture(Texture* texture);
    };

}}
