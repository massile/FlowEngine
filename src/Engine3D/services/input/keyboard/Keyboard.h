#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "IKeyboard.h"

class Keyboard : public IKeyboard
{
private:
    bool m_keys[MAX_KEYS] = {false};

public:
    bool isKeyPressed(int key) const override { return m_keys[key]; }
    friend void key_callback(GLFWwindow* window, int key, int scanCode, int action, int mods);
};

void key_callback(GLFWwindow* window, int key, int scanCode, int action, int mods);
