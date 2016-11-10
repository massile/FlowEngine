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
            glEnableVertexAttribArray(SHADER_UV_INDEX);
            glEnableVertexAttribArray(SHADER_TID_INDEX);

            glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::position));
            glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::color));
            glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::uv));
            glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::tid));
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
            const GLuint color = renderable->getColor();
            const std::vector<glm::vec2>& uvs = renderable->getUvs();
            const GLuint tid = renderable->getTId();

            float ts = 0.0f;
            if (tid > 0) {
                bool found = false;
                for (int i = 0; i < m_TextureSlots.size(); i++) {
                    if (m_TextureSlots[i] == tid) {
                        ts = i + 1;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    m_TextureSlots.push_back(tid);
                    ts = m_TextureSlots.size();
                    if (ts >= RENDERER_MAX_TEXTURES) {
                        end();
                        flush();
                        begin();
                    }
                }
            }

            m_Buffer->position = (*m_TransformationBack) * glm::vec4(pos, 1.0f);
            m_Buffer->color = color;
            m_Buffer->uv = uvs[0];
            m_Buffer->tid = ts;
            m_Buffer++;

            m_Buffer->position = (*m_TransformationBack) * glm::vec4(pos.x, pos.y + size.y, pos.z, 1.0f);
            m_Buffer->color = color;
            m_Buffer->uv = uvs[1];
            m_Buffer->tid = ts;
            m_Buffer++;

            m_Buffer->position = (*m_TransformationBack) * glm::vec4(pos.x + size.x, pos.y + size.y, pos.z, 1.0f);
            m_Buffer->color = color;
            m_Buffer->uv = uvs[2];
            m_Buffer->tid = ts;
            m_Buffer++;

            m_Buffer->position = (*m_TransformationBack) * glm::vec4(pos.x + size.x, pos.y, pos.z, 1.0f);
            m_Buffer->color = color;
            m_Buffer->uv = uvs[3];
            m_Buffer->tid = ts;
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
            for(int i=0; i<m_TextureSlots.size(); i++) {
                glActiveTexture(GL_TEXTURE0 + i);
                glBindTexture(GL_TEXTURE_2D, m_TextureSlots[i]);
            }

            glBindVertexArray(m_VAO);
            m_IBO->bind();

            glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

            m_IBO->unbind();
            glBindVertexArray(0);

            m_IndexCount = 0;
        }

    } }