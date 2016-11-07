#pragma once

#include "buffer/vertexBuffer.h"
#include "buffer/indexBuffer.h"
#include "buffer/vertexArray.h"

#include "shader.h"
#include "renderer2d.h"

namespace FlowEngine { namespace Graphics {
    struct VertexData
    {
        glm::vec3 position;
        GLuint color;
        glm::vec2 uv;
    };

    class Renderable2D
    {
    protected:
        glm::vec3 m_Position;
        glm::vec2 m_Size;
        glm::vec4 m_Color;
        std::vector<glm::vec2> m_Uvs;

    protected:
        Renderable2D() {}

    public:
        Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color)
                : m_Position(position), m_Size(size), m_Color(color)
        { setDefaultUv(); }

        virtual ~Renderable2D() { setDefaultUv(); }

        virtual void submit(Renderer2D* renderer) const { renderer->submit(this); }
        inline const glm::vec3& getPosition() const { return m_Position; }
        inline const glm::vec2& getSize() const { return m_Size; }
        inline const glm::vec4& getColor() const { return m_Color; }
        inline const std::vector<glm::vec2>& getUvs() const { return m_Uvs; }

    private:
        void setDefaultUv()
        {
            m_Uvs.push_back(glm::vec2(0, 0));
            m_Uvs.push_back(glm::vec2(0, 1));
            m_Uvs.push_back(glm::vec2(1, 1));
            m_Uvs.push_back(glm::vec2(1, 0));
        }
    };
}}