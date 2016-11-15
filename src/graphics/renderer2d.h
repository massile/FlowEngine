#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "texture.h"
#include "mask.h"

namespace FlowEngine { namespace Graphics {

    class Renderable2D;
    class Renderer2D
    {
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
