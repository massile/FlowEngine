#pragma once

#include "IMouse.h"
#include "../../ui/window/IWindow.h"

class Mouse : public IMouse
{
private:
    bool m_mouse_buttons[MAX_BUTTONS] = {false};
    glm::vec2 m_cursor_position = {0, 0};
    glm::vec2 m_previous_cursor_position = {0, 0};

public:
    Mouse();
    virtual ~Mouse();

    bool isMouseButtonPressed(int button) const override { return m_mouse_buttons[button]; }
    glm::vec2 getCursorPosition() const override { return m_cursor_position; }
    glm::vec2 getCursorPositionOffset() const override;
    void update() override;

    friend void cursor_position_callback(GLFWwindow* window, double x, double y);
    friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
};

void cursor_position_callback(GLFWwindow* window, double x, double y);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
