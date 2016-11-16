#pragma once

#include "../Renderable2d.h"
#include "../Renderer2d.h"

namespace FlowEngine { namespace Graphics {

    class Group : public Renderable2D
    {
    private:
        std::vector<Renderable2D*> mRenderables;
        glm::mat4 mTransformationMatrix;
    public:
        Group(const glm::mat4& transform);

        void add(Renderable2D* renderable);
        void submit(Renderer2D* renderer) const override;
    };

}}
