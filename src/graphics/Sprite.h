#pragma once

#include "buffer/VertexBuffer.h"
#include "buffer/IndexBuffer.h"
#include "buffer/VertexArray.h"

#include "Shader.h"
#include "Renderer2d.h"
#include "Texture.h"
#include "IRenderable.h"

namespace FlowEngine { namespace Graphics {

    class Sprite : public IRenderable<Renderer2D>
    {
    protected:
        glm::vec3 mPosition;
        glm::vec2 mSize;
        uint mColor;
        std::vector<glm::vec2> mUVs;
        Texture* mTexture = nullptr;

    protected:
        Sprite() {}


    public:
        Sprite(glm::vec3 position, glm::vec2 size, GLuint color);
        Sprite(float x, float y, float width, float height, uint color);
        Sprite(float x, float y, float width, float height, Texture* texture);

        virtual ~Sprite() {}

        void render(Renderer2D& renderer) const override { renderer.submit(this); }

        inline const glm::vec3& getPosition() const { return mPosition; }
        inline const glm::vec2& getSize() const { return mSize; }
        inline uint getColor() const { return mColor; }
        inline const std::vector<glm::vec2>& getUvs() const { return mUVs; }
        inline const float getTId() const { return mTexture ? mTexture->getId() : 0; }
        inline Texture* getTexture() const { return mTexture; }

        inline void setColor(const glm::vec4& color);
        inline glm::vec3 setPosition(const glm::vec3& position) { mPosition = position; }

    private:
        void setDefaultUv();
    };

}}
