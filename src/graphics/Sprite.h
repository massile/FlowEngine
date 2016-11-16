#pragma once

#include "Renderable2d.h"

namespace FlowEngine { namespace Graphics {

    class Sprite : public Renderable2D
    {
    public:
        Sprite(float x, float y, float width, float height, uint color);
        Sprite(float x, float y, float width, float height, Texture* texture);

        inline glm::vec3 getPosition() const { return mPosition; }
        inline glm::vec3 setPosition(const glm::vec3& position) { mPosition = position; }
    };

}}
