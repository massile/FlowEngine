#pragma once

#include <GL/glew.h>
#include <string>
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

public:
    Window(const std::string& title, int width, int height);
    virtual ~Window();

    bool shouldClose() const override { return glfwWindowShouldClose(m_window) == 1; }
    int getWidth() const override { return m_width; }
    int getHeight() const override { return m_height; }

    void clear() const override;
    void update() override;

private:
    bool initWindowPointer();
    void setCallbacks();
};

void error_callback(int error, const char* description);