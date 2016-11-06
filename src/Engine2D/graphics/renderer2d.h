#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace FlowEngine { namespace Graphics {

    class Renderable2D;
    class Renderer2D
    {
    protected:
        std::vector<glm::mat4> m_TransformationStack;
        const glm::mat4* m_TransformationBack;

    public:
        Renderer2D();
        void push(const glm::mat4& matrix, bool override = false);
        void pop();

        virtual void submit(const Renderable2D* renderable) = 0;
        virtual void begin() = 0;
        virtual void flush() = 0;
        virtual void end() = 0;
    };
}}