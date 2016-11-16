#pragma once

#include <vector>
#include "../../events/IEventListener.h"

namespace FlowEngine { namespace Graphics {

    template<typename T>
    class Layer : public Events::IEventListener
    {
    protected:
        T* mRenderer;

    public:
        Layer(T* renderer) : mRenderer(renderer) {}
        virtual void render() = 0;

    };

}}
