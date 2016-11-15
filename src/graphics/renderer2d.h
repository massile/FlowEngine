#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "texture.h"
#include "mask.h"

namespace FlowEngine { namespace Graphics {

    class Renderable2D;
    struct VertexData
    {
        glm::vec3 position;
        uint color;
        glm::vec2 uv;
        glm::vec2 maskUv;
        float tid;
        float mid;
    };

    class Renderer2D
    {
    public:
        static const uint VERTEX_BYTE_SIZE = sizeof(VertexData);
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
        void push(const glm::mat4& matrix, bool override = false);
        void pop();

        virtual void submit(const Renderable2D* renderable) = 0;
        virtual void begin() = 0;
        virtual void flush() = 0;
        virtual void end() = 0;

        void setMask(const Mask* mask) { mMask = mask; }
    };

}}
