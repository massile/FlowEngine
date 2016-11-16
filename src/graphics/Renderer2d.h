#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Texture.h"
#include "Mask.h"
#include "IRenderer.h"
#include "Vertex.h"

namespace FlowEngine { namespace Graphics {

    class Renderable2D;
    class Renderer2D : public IRenderer<Renderable2D>
    {
    public:
        static const uint VERTEX_BYTE_SIZE = sizeof(Vertex2D);
        static const uint SPRITE_BYTE_SIZE = VERTEX_BYTE_SIZE * 4;

        static const uint MAX_SPRITES = 60000;
        static const uint MAX_TEXTURES = 31;
        static const uint MAX_VERTEX_BUFFER_BYTE_SIZE = SPRITE_BYTE_SIZE * MAX_SPRITES;
        static const uint MAX_INDICES_BYTE_SIZE = MAX_SPRITES * 6;
    protected:
        std::vector<glm::mat4> mTransformationStack;
        const glm::mat4* mTransformationBack;
        const Mask* mMask;
    public:
        Renderer2D();
        void setMask(const Mask* mask) { mMask = mask; }

        void push(const glm::mat4& matrix, bool override = false);
        void pop();
    };

}}
