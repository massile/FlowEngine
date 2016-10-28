#include "Ui.h"

IWindow* Ui::m_window;
NullWindow Ui::m_nullWindow;

void Ui::provide(IWindow *window)
{
    if(window == nullptr) {
        m_window = &m_nullWindow;
    }
    else {
        m_window = window;
    }
}
