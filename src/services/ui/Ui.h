#pragma once

#include "window/IWindow.h"
#include "window/NullWindow.h"

class Ui
{
public:
    static IWindow* getWindow() { return m_window; }
    static void provide(IWindow* window);
private:
    static IWindow* m_window;
    static NullWindow m_nullWindow;
};