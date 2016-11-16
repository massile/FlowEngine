#pragma once

namespace FlowEngine { namespace Graphics {

    template <typename T>
    interface IRenderable
    {
    public:
        virtual void render(T& renderer) const = 0;
    };

}}
