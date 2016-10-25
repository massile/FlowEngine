#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
private:
    std::string m_title;
    int m_width;
    int m_height;
    GLFWwindow* m_window = nullptr;

public:
    Window(const std::string& title, int width, int height);
    ~Window();

    inline bool shouldClose() const { return glfwWindowShouldClose(m_window) == 1; }
    inline int getWidth() const { return m_width; }
    inline int getHeight() const { return m_height; }

    void clear() const;
    void update(float dt);

private:
    bool initWindowPointer();
};

void error_callback(int error, const char* description);
