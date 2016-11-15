#include "renderer2d.h"

namespace FlowEngine { namespace Graphics {

    Renderer2D::Renderer2D()
    {
        mTransformationStack.push_back(glm::mat4(1.0f));
        mTransformationBack = &mTransformationStack.back();
    }

    void Renderer2D::push(const glm::mat4 &matrix, bool override)
    {
        mTransformationStack.push_back(override ? matrix : mTransformationStack.back() * matrix);
        mTransformationBack = &mTransformationStack.back();
    }

    void Renderer2D::pop()
    {
        if (mTransformationStack.size() > 1)
            mTransformationStack.pop_back();
        mTransformationBack = &mTransformationStack.back();
    }

}}
