#include "Mouse.h"
#include "../Input.h"

Mouse::Mouse()
{

}

Mouse::~Mouse()
{

}

void Mouse::update()
{
    m_previous_cursor_position = m_cursor_position;
}

glm::vec2 Mouse::getCursorPositionOffset() const
{
    return glm::vec2(
            m_cursor_position.x - m_previous_cursor_position.x,
            m_previous_cursor_position.y - m_cursor_position.y
    );
}

void cursor_position_callback(GLFWwindow *window, double x, double y)
{
    Mouse* mouse = static_cast<Mouse*>(Input::getMouse());
    mouse->m_cursor_position = glm::vec2(x, y);
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    Mouse* mouse = static_cast<Mouse*>(Input::getMouse());
    mouse->m_mouse_buttons[button] = action != GLFW_RELEASE;
}

