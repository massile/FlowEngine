#pragma once

namespace FlowEngine { namespace Events {

    enum class EventType { MOUSE_PRESSED, MOUSE_RELEASED, MOUSE_MOVED, KEY_PRESSED, KEY_RELEASED };

    class Event
    {
    protected:
        EventType mType;

    protected:
        Event(EventType type);
        inline EventType getType() const { return mType; }
    };

}}
