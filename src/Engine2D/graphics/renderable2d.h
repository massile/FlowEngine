#pragma once

#include "buffer/vertexBuffer.h"
#include "buffer/indexBuffer.h"
#include "buffer/vertexArray.h"

#include "shader.h"

namespace FlowEngine { namespace Graphics {
    struct VertexData
    {
        glm::vec3 position;
        GLuint color;
    };

    class Renderable2D
    {
    protected:
        glm::vec3 m_Position;
        glm::vec2 m_Size;
        glm::vec4 m_Color;
    public:
        Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color)
                : m_Position(position), m_Size(size), m_Color(color)
        { }

        virtual ~Renderable2D() { }

        inline const glm::vec3& getPosition() const { return m_Position; }
        inline const glm::vec2& getSize() const { return m_Size; }
        inline const glm::vec4& getColor() const { return m_Color; }
    };
}}