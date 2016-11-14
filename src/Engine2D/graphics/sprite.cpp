#include "sprite.h"

namespace FlowEngine { namespace Graphics {

    Sprite::Sprite(float x, float y, float width, float height, uint color)
            : Renderable2D(glm::vec3(x, y, 0), glm::vec2(width, height), color)
    {}

    Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
            : Renderable2D(glm::vec3(x, y, 0), glm::vec2(width, height), 0xffffff)
    {
        mTexture = texture;
    }

}}
