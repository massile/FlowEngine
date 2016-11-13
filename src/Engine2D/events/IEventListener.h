#pragma once

#include "Event.h"

namespace FlowEngine { namespace Events {

    interface IEventListener
    {
    public:
        virtual bool onEvent(const Event& event) = 0;
    };

}}
