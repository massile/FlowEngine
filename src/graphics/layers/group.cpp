#include "group.h"

namespace FlowEngine { namespace Graphics {

    Group::Group(const glm::mat4& transform)
            : mTransformationMatrix(transform)
    {
    }

    void Group::add(Renderable2D* renderable)
    {
        mRenderables.push_back(renderable);
    }

    void Group::submit(Renderer2D* renderer) const
    {
        renderer->push(mTransformationMatrix);

        for (Renderable2D* renderable : mRenderables)
            renderable->submit(renderer);

        renderer->pop();
    }

}}
