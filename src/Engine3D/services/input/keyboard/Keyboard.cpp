#include "Keyboard.h"
#include "../Input.h"

void key_callback(GLFWwindow *window, int key, int scanCode, int action, int mods)
{
    Keyboard* keyboard = static_cast<Keyboard*>(Input::getKeyboard());
    keyboard->m_keys[key] = action != GLFW_RELEASE;
}
