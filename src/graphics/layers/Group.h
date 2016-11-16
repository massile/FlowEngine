#pragma once

#include "../Sprite.h"
#include "../Renderer2d.h"

namespace FlowEngine { namespace Graphics {

    class Group : public Sprite
    {
    private:
        std::vector<Sprite*> mRenderables;
        glm::mat4 mTransformationMatrix;
    public:
        Group(const glm::mat4& transform);

        void add(Sprite* renderable);
        void render(Renderer2D& renderer) const override;
    };

}}
