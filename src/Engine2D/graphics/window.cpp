#include "window.h"
#include "../textureManager.h"

namespace FlowEngine { namespace Graphics {

    Window::Window(const std::string& title, int width, int height)
    {
        mTitle = title;
        m_Width = width;
        mHeight = height;
        if (!init())
            glfwTerminate();
    }

    Window::~Window()
    {
        TextureManager::clean();
        glfwDestroyWindow(mWindow);
        glfwTerminate();
    }

    bool Window::init()
    {
        if (!glfwInit())
        {
            std::cout << "Failed to initialize GLFW!" << std::endl;
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        mWindow = glfwCreateWindow(m_Width, mHeight, mTitle.c_str(), NULL, NULL);
        if (!mWindow)
        {
            std::cout << "Failed to create GLFW window!" << std::endl;
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwMakeContextCurrent(mWindow);
        glfwSwapInterval(0.0);

        glfwSetWindowUserPointer(mWindow, this);
        glfwSetKeyCallback(mWindow, key_callback);
        glfwSetMouseButtonCallback(mWindow, mouse_button_callback);
        glfwSetCursorPosCallback(mWindow, cursor_position_callback);
        glfwSetWindowSizeCallback(mWindow, window_resize);

        if (glewInit() != GLEW_OK)
        {
            std::cout << "Could not initialize GLEW!" << std::endl;
            return false;
        }

        std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
        return true;
    }

    bool Window::isKeyPressed(unsigned int keycode) const
    {
        if (keycode >= MAX_KEYS)
            return false;
        return mKeys[keycode];
    }

    bool Window::isMouseButtonPressed(unsigned int button) const
    {
        if (button >= MAX_BUTTONS)
            return false;

        return mMouseButtons[button];
    }

    void Window::clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::update()
    {
        glfwPollEvents();
        glfwSwapBuffers(mWindow);
    }

    bool Window::closed() const
    {
        return glfwWindowShouldClose(mWindow) == 1;
    }

    void window_resize(GLFWwindow *window, int width, int height)
    {
        Window* win = (Window*)glfwGetWindowUserPointer(window);
        win->m_Width = width;
        win->mHeight = height;
        glViewport(0, 0, width, height);
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        Window* win = (Window*)glfwGetWindowUserPointer(window);
        win->mKeys[key] = action != GLFW_RELEASE;
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
    {
        Window* win = (Window*)glfwGetWindowUserPointer(window);
        win->mMouseButtons[button] = action != GLFW_RELEASE;
    }

    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
        Window* win = (Window*)glfwGetWindowUserPointer(window);
        win->mMousePosition = glm::vec2(xpos, ypos);
    }
}}