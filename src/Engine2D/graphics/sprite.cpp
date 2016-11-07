#include "sprite.h"

namespace FlowEngine { namespace Graphics {
    Sprite::Sprite(float x, float y, float width, float height, const glm::vec4& color)
            : Renderable2D(glm::vec3(x, y, 0), glm::vec2(width, height), color)
    {}

    Sprite::Sprite(float x, float y, float width, float height, Texture* texture)
            : Renderable2D(glm::vec3(x, y, 0), glm::vec2(width, height), glm::vec4(1, 0, 1, 1))
    {
        m_Texture = texture;
    }
} }