#pragma once

#include "Renderer3d.h"

namespace FlowEngine { namespace Graphics {

    class ForwardRenderer : public Renderer3D
    {
    public:
        void submit(const Mesh *renderable) override;
        void begin() override;
        void flush() override;
        void end() override;
    };

}}
