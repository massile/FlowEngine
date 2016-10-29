#pragma once

#include <GL/glew.h>
#include <string>
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
};
