#include "MouseEvent.h"

namespace FlowEngine { namespace Events {

    MouseEvent::MouseEvent(int button, double x, double y, EventType type)
            : Event(type), mButton(button), mPosition(glm::vec2(x, y)) {}

    MousePressedEvent::MousePressedEvent(int button, double x, double y)
            : MouseEvent(button, x, y, EventType::MOUSE_PRESSED) {}

    MouseReleasedEvent::MouseReleasedEvent(int button, double x, double y)
            : MouseEvent(button, x, y, EventType::MOUSE_RELEASED) {}

}}
