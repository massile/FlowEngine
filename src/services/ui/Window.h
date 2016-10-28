#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include "IWindow.h"

class Window : public IWindow
{
private:
    std::string m_title;
    int m_width;
    int m_height;
    GLFWwindow* m_window = nullptr;

    bool m_keys[MAX_KEYS] = {false};
    bool m_mouse_buttons[MAX_BUTTONS] = {false};
    glm::vec2 m_cursor_position;
    glm::vec2 m_previous_cursor_position;

public:
    Window(const std::string& title, int width, int height);
    virtual ~Window();

    bool shouldClose() const override { return glfwWindowShouldClose(m_window) == 1; }
    int getWidth() const override { return m_width; }
    int getHeight() const override { return m_height; }

    void clear() const override;
    void update() override;

    bool isKeyPressed(int key) const override { return m_keys[key]; }
    bool isMouseButtonPressed(int button) const override { return m_mouse_buttons[button]; }
    glm::vec2 getCursorPosition() const override { return m_cursor_position; }
    glm::vec2 getCursorPositionOffset() const override;

    friend void key_callback(GLFWwindow* window, int key, int scanCode, int action, int mods);
    friend void cursor_position_callback(GLFWwindow* window, double x, double y);
    friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

private:
    bool initWindowPointer();
    void setCallbacks();
};

void error_callback(int error, const char* description);
void key_callback(GLFWwindow* window, int key, int scanCode, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double x, double y);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
