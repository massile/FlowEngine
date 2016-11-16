#include "Group.h"

namespace FlowEngine { namespace Graphics {

    Group::Group(const glm::mat4& transform)
            : mTransformationMatrix(transform)
    {
    }

    void Group::add(Sprite* renderable)
    {
        mRenderables.push_back(renderable);
    }

    void Group::render(Renderer2D& renderer) const
    {
        renderer.push(mTransformationMatrix);

        for (Sprite* renderable : mRenderables)
            renderable->render(renderer);

        renderer.pop();
    }

}}
