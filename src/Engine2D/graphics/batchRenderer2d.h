#pragma once

#include "renderer2d.h"
#include "buffer/indexBuffer.h"
#include "renderable2d.h"
#include "frameBuffer.h"

namespace FlowEngine { namespace Graphics {

#define RENDERER_MAX_SPRITES	60000
#define RENDERER_MAX_TEXTURES   31
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

    enum ShaderIndex { POSITION, COLOR, UV, MASK_UV, TID, MID, FIRST=0, LAST=MID };
    enum RenderTarget { SCREEN, BUFFER };

    class BatchRenderer2D : public Renderer2D
    {
    private:
        GLuint mVAO;
        GLuint mVBO;
        IndexBuffer* mIBO;
        GLsizei mIndexCount;
        VertexData* mBuffer;
        std::vector<GLuint> mTextureSlots;

        Shader* mFramebufferShader;
        FrameBuffer* mFrameBuffer;
        glm::vec2 mScreenSize;
        GLuint mScreenQuad;
        RenderTarget mTarget = SCREEN;
    public:
        BatchRenderer2D(const glm::vec2& screenSize);
        ~BatchRenderer2D();

        void begin() override;
        void submit(const Renderable2D* renderable) override;
        void end() override;
        void flush() override;

        void setTarget(RenderTarget target) { mTarget = target; }
    private:
        void init();
        float submitTexture(GLuint textureID);
        float submitTexture(Texture* texture);
    };

}}
