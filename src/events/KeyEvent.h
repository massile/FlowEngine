#pragma once

#include "Event.h"

namespace FlowEngine { namespace Events {

    class KeyEvent : Event
    {
    private:
        int mKeyCode;
    public:
        KeyEvent(int keyCode, EventType type);
        inline const int getKeyCode() const {return mKeyCode; }
    };

    class KeyPressedEvent : KeyEvent
    {
    private:
        int mRepeat;
    public:
        KeyPressedEvent(int button, int repeat);
        inline const int getRepeat() const { return mRepeat; }
    };

    class KeyReleasedEvent : KeyEvent
    {
    public:
        KeyReleasedEvent(int button);
    };

}}
