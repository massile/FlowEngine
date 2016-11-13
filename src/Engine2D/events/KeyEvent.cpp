#include "KeyEvent.h"

namespace FlowEngine { namespace Events {

    KeyEvent::KeyEvent(int keyCode, EventType type)
            : Event(type), mKeyCode(keyCode) {}

    KeyPressedEvent::KeyPressedEvent(int button, int repeat)
            : KeyEvent(button, EventType::KEY_PRESSED), mRepeat(repeat) {}

    KeyReleasedEvent::KeyReleasedEvent(int button)
            : KeyEvent(button, EventType::KEY_RELEASED) {}
}}
