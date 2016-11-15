#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#define MAX_KEYS	1024
#define MAX_BUTTONS	32

namespace FlowEngine { namespace Graphics {

    class Window
    {
    private:
        std::string mTitle;
        int m_Width, mHeight;
        GLFWwindow *mWindow;

        bool mKeys[MAX_KEYS];
        bool mKeyStates[MAX_KEYS];
        bool mKeyTyped[MAX_KEYS];

        bool mMouseButtons[MAX_BUTTONS];
        bool mMouseStates[MAX_BUTTONS];
        bool mMouseClicked[MAX_BUTTONS];
        bool mMouseGrabbed;

        glm::vec2 mMousePosition;

    public:
        Window(const std::string& name, int width, int height);
        ~Window();
        void clear() const;
        void update();
        bool closed() const;

        bool isKeyPressed(unsigned int keycode) const;
        bool isKeyTyped(unsigned int keycode) const;
        bool isMouseButtonPressed(unsigned int button) const;
        bool isMouseButtonClicked(unsigned int button) const;

        const glm::vec2& getMousePosition() const;
        const bool isMouseGrabbed() const;

        inline int getWidth() const { return m_Width; }
        inline int getHeight() const { return mHeight; }

    private:
        bool init();
        friend void window_resize(GLFWwindow *window, int width, int height);
        friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    };

    void window_resize(GLFWwindow *window, int width, int height);
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

}}
