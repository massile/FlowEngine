#include "Window.h"
#include "../../input/mouse/Mouse.h"
#include "../../input/keyboard/Keyboard.h"
#include <iostream>

Window::Window(const std::string &title, int width, int height)
        : m_height(height), m_width(width), m_title(title)
{
    if(!glfwInit()) {
        std::cout << "Can't initialize GLFW" << std::endl;
        glfwTerminate();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if(!initWindowPointer()) {
        std::cout << "Can't create window" << std::endl;
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
    glewInit();
    glewExperimental = true;

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(m_window, width/2, height/2);
    glEnable(GL_DEPTH_TEST);

    setCallbacks();
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::setCallbacks()
{
    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(m_window, key_callback);
    glfwSetCursorPosCallback(m_window, cursor_position_callback);
    glfwSetMouseButtonCallback(m_window, mouse_button_callback);
}

bool Window::initWindowPointer()
{
    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    if(!m_window) {
        return false;
    }
    glfwMakeContextCurrent(m_window);

    return true;
}

void Window::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwPollEvents();
}

void Window::update()
{
    glfwSwapBuffers(m_window);
}

void error_callback(int error, const char *description)
{
    std::cout << "Error#" << error << ": " << description << std::endl;
}