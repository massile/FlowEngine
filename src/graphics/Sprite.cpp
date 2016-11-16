#include "Sprite.h"

namespace FlowEngine { namespace Graphics {

    Sprite::Sprite(float x, float y, float width, float height, uint color)
            : Sprite(glm::vec3(x, y, 0), glm::vec2(width, height), color)
    {

    }

    Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
            : Sprite(glm::vec3(x, y, 0), glm::vec2(width, height), 0xffffff)
    {
        mTexture = texture;
    }

    Sprite::Sprite(glm::vec3 position, glm::vec2 size, uint color)
            : mPosition(position), mSize(size), mColor(color)
    {
        setDefaultUv();
    }

    void Sprite::setColor(const glm::vec4 &color)
    {
        glm::vec4 col = 255.0f * color;
        mColor = (int)col.a << 24 | (int)col.b << 16 | (int)col.g << 8 | (int)col.r;
    }

    void Sprite::setDefaultUv()
    {
        mUVs.push_back(glm::vec2(0, 0));
        mUVs.push_back(glm::vec2(0, 1));
        mUVs.push_back(glm::vec2(1, 1));
        mUVs.push_back(glm::vec2(1, 0));
    }

}}
