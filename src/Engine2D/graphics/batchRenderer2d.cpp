#include "batchRenderer2d.h"

namespace FlowEngine { namespace Graphics {

        BatchRenderer2D::BatchRenderer2D()
        {
            init();
        }

        BatchRenderer2D::~BatchRenderer2D()
        {
            delete m_IBO;
            glDeleteBuffers(1, &m_VBO);
        }

        void BatchRenderer2D::init()
        {
            glGenVertexArrays(1, &m_VAO);
            glGenBuffers(1, &m_VBO);

            glBindVertexArray(m_VAO);
            glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
            glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
            glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
            glEnableVertexAttribArray(SHADER_COLOR_INDEX);
            glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::position));
            glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::color));
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            GLuint* indices = new GLuint[RENDERER_INDICES_SIZE];

            int offset = 0;
            for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
            {
                indices[i] = offset + 0;
                indices[i + 1] = offset + 1;
                indices[i + 2] = offset + 2;

                indices[i + 3] = offset + 2;
                indices[i + 4] = offset + 3;
                indices[i + 5] = offset + 0;

                offset += 4;
            }

            m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

            glBindVertexArray(0);
        }

        void BatchRenderer2D::begin()
        {
            glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
            m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        }

        void BatchRenderer2D::submit(const Renderable2D* renderable)
        {
            const glm::vec3& pos = renderable->getPosition();
            const glm::vec2& size = renderable->getSize();
            const glm::vec4& color = 255.0f * renderable->getColor();
            GLuint c = (int)color.a << 24 | (int)color.b << 16 | (int)color.g << 8 | (int)color.r;

            m_Buffer->position = (*m_TransformationBack) * glm::vec4(pos, 1.0f);
            m_Buffer->color = c;
            m_Buffer++;

            m_Buffer->position = (*m_TransformationBack) * glm::vec4(pos.x, pos.y + size.y, pos.z, 1.0f);
            m_Buffer->color = c;
            m_Buffer++;

            m_Buffer->position = (*m_TransformationBack) * glm::vec4(pos.x + size.x, pos.y + size.y, pos.z, 1.0f);
            m_Buffer->color = c;
            m_Buffer++;

            m_Buffer->position = (*m_TransformationBack) * glm::vec4(pos.x + size.x, pos.y, pos.z, 1.0f);
            m_Buffer->color = c;
            m_Buffer++;

            m_IndexCount += 6;
        }

        void BatchRenderer2D::end()
        {
            glUnmapBuffer(GL_ARRAY_BUFFER);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void BatchRenderer2D::flush()
        {
            glBindVertexArray(m_VAO);
            m_IBO->bind();

            glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

            m_IBO->unbind();
            glBindVertexArray(0);

            m_IndexCount = 0;
        }

    } }