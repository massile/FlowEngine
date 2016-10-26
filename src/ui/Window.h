#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#define MAX_KEYS 500
#define MAX_BUTTONS 8

class Window
{
private:
    std::string m_title;
    int m_width;
    int m_height;
    GLFWwindow* m_window = nullptr;

    bool m_keys[MAX_KEYS] = {false};
    bool m_mouse_buttons[MAX_BUTTONS] = {false};
    glm::vec2 m_cursor_position;

public:
    Window(const std::string& title, int width, int height);
    ~Window();

    inline bool shouldClose() const { return glfwWindowShouldClose(m_window) == 1; }
    inline int getWidth() const { return m_width; }
    inline int getHeight() const { return m_height; }

    void clear() const;
    void update(float dt);

    inline bool isKeyPressed(int key) const { return m_keys[key]; }
    inline bool isMouseButtonPressed(int button) const { return m_mouse_buttons[button]; }
    inline glm::vec2 getCursorPosition() const { return m_cursor_position; }

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
