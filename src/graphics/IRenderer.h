#pragma once

#include "Mesh.h"

namespace FlowEngine { namespace Graphics {

    template <class T>
    interface IRenderer
    {
    public:
        virtual void submit(const T* renderable) = 0;
        virtual void begin() = 0;
        virtual void flush() = 0;
        virtual void end() = 0;
    };

}}
