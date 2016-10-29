#pragma once

#include "keyboard/IKeyboard.h"
#include "keyboard/NullKeyboard.h"
#include "mouse/IMouse.h"
#include "mouse/NullMouse.h"

class Input
{
public:
    static IKeyboard* getKeyboard() { return m_keyboard; }
    static IMouse* getMouse() { return m_mouse; }
    static void provide(IKeyboard* keyboard, IMouse* mouse);
private:
    static IKeyboard* m_keyboard;
    static IMouse* m_mouse;
    static NullKeyboard m_nullKeyboard;
    static NullMouse m_nullMouse;
};