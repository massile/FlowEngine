#include "renderer2d.h"

namespace FlowEngine { namespace Graphics {

    Renderer2D::Renderer2D()
    {
        m_TransformationStack.push_back(glm::mat4(1.0f));
        m_TransformationBack = &m_TransformationStack.back();
    }

    void Renderer2D::push(const glm::mat4 &matrix, bool override)
    {
        m_TransformationStack.push_back(override ? matrix : m_TransformationStack.back() * matrix);
        m_TransformationBack = &m_TransformationStack.back();
    }

    void Renderer2D::pop()
    {
        if (m_TransformationStack.size() > 1)
            m_TransformationStack.pop_back();
        m_TransformationBack = &m_TransformationStack.back();
    }

}}