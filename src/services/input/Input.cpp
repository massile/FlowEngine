#include "Input.h"

IKeyboard* Input::m_keyboard ;
IMouse* Input::m_mouse;
NullKeyboard Input::m_nullKeyboard;
NullMouse Input::m_nullMouse;

void Input::provide(IKeyboard* keyboard, IMouse* mouse)
{
    if(keyboard == nullptr) {
        m_keyboard = &m_nullKeyboard;
    }
    else {
        m_keyboard = keyboard;
    }

    if(mouse == nullptr) {
        m_mouse = &m_nullMouse;
    }
    else {
        m_mouse = mouse;
    }
}
