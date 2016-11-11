#include "renderable2d.h"

namespace FlowEngine { namespace Graphics {

    Renderable2D::Renderable2D(glm::vec3 position, glm::vec2 size, GLuint color)
            : mPosition(position), mSize(size), mColor(color)
    {
        setDefaultUv();
    }

    void Renderable2D::setColor(const glm::vec4 &color)
    {
        glm::vec4 col = 255.0f * color;
        mColor = (int)col.a << 24 | (int)col.b << 16 | (int)col.g << 8 | (int)col.r;
    }

    void Renderable2D::setDefaultUv()
    {
        mUVs.push_back(glm::vec2(0, 0));
        mUVs.push_back(glm::vec2(0, 1));
        mUVs.push_back(glm::vec2(1, 1));
        mUVs.push_back(glm::vec2(1, 0));
    }

}}
