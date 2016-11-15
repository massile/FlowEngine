#pragma once

#include "buffer/vertexBuffer.h"
#include "buffer/indexBuffer.h"
#include "buffer/vertexArray.h"

#include "shader.h"
#include "renderer2d.h"
#include "texture.h"

namespace FlowEngine { namespace Graphics {

    struct VertexData
    {
        glm::vec3 position;
        uint color;
        glm::vec2 uv;
        glm::vec2 maskUv;
        float tid;
        float mid;
    };

    class Renderable2D
    {
    protected:
        glm::vec3 mPosition;
        glm::vec2 mSize;
        uint mColor;
        std::vector<glm::vec2> mUVs;
        Texture* mTexture = nullptr;

    protected:
        Renderable2D() {}

    public:
        Renderable2D(glm::vec3 position, glm::vec2 size, GLuint color);
        virtual ~Renderable2D() {}

        virtual void submit(Renderer2D* renderer) const { renderer->submit(this); }

        inline const glm::vec3& getPosition() const { return mPosition; }
        inline const glm::vec2& getSize() const { return mSize; }
        inline uint getColor() const { return mColor; }
        inline const std::vector<glm::vec2>& getUvs() const { return mUVs; }
        inline const float getTId() const { return mTexture ? mTexture->getId() : 0; }
        inline Texture* getTexture() const { return mTexture; }

        void setColor(const glm::vec4& color);

    private:
        void setDefaultUv();
    };

}}
