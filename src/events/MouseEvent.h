#pragma once

#include <glm/vec2.hpp>
#include "Event.h"

namespace FlowEngine { namespace Events {

    class MouseEvent : Event
    {
    private:
        int mButton;
        glm::vec2 mPosition;
    public:
        MouseEvent(int button, double x, double y, EventType type);

        inline const glm::vec2& getPosition() const { return mPosition; }
        inline const int getButton() const { return mButton; }
    };

    class MousePressedEvent : MouseEvent
    {
    public:
        MousePressedEvent(int button, double x, double y);
    };

    class MouseReleasedEvent : MouseEvent
    {
    public:
        MouseReleasedEvent(int button, double x, double y);
    };

}}
