#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include "IWindow.h"

class NullWindow : public IWindow
{
public:
    virtual ~NullWindow() {}

    bool shouldClose() const override { return false; }
    int getWidth() const override { return 0; }
    int getHeight() const override { return 0; }

    void clear() const override {}
    void update() override {}

    bool isKeyPressed(int key) const override { return false; }
    bool isMouseButtonPressed(int button) const override { return false; }
    glm::vec2 getCursorPosition() const override { return glm::vec2(); }
    glm::vec2 getCursorPositionOffset() const override { return glm::vec2(); }
};
