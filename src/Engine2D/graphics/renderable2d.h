#pragma once

#include "buffer/vertexBuffer.h"
#include "buffer/indexBuffer.h"
#include "buffer/vertexArray.h"

#include "shader.h"
#include "renderer2d.h"
#include "texture.h"

namespace FlowEngine { namespace Graphics {
    struct VertexData
    {
        glm::vec3 position;
        GLuint color;
        glm::vec2 uv;
        float tid;
    };

    class Renderable2D
    {
    protected:
        glm::vec3 m_Position;
        glm::vec2 m_Size;
        GLuint m_Color;
        std::vector<glm::vec2> m_Uvs;
        Texture* m_Texture = nullptr;

    protected:
        Renderable2D() {}

    public:
        Renderable2D(glm::vec3 position, glm::vec2 size, GLuint color)
                : m_Position(position), m_Size(size), m_Color(color)
        { setDefaultUv(); }

        virtual ~Renderable2D() { setDefaultUv(); }

        virtual void submit(Renderer2D* renderer) const { renderer->submit(this); }
        inline const glm::vec3& getPosition() const { return m_Position; }
        inline const glm::vec2& getSize() const { return m_Size; }
        inline GLuint getColor() const { return m_Color; }
        void setColor(const glm::vec4& color)
        {
            glm::vec4 col = 255.0f * color;
            m_Color = (int)col.a << 24 | (int)col.b << 16 | (int)col.g << 8 | (int)col.r;
        }
        inline const std::vector<glm::vec2>& getUvs() const { return m_Uvs; }
        inline const float getTId() const { return m_Texture ? m_Texture->getId() : 0; }

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