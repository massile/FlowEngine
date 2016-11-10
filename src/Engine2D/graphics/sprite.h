#pragma once

#include "renderable2d.h"

namespace FlowEngine { namespace Graphics {

    class Sprite : public Renderable2D
    {
    public:
        Sprite(float x, float y, float width, float height, GLuint color);
        Sprite(float x, float y, float width, float height, Texture* texture);
    };

}}