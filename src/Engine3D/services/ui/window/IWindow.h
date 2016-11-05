#pragma once

#include <GL/glew.h>
#include <string>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

class IWindow
{
public:
    virtual ~IWindow() {}

    virtual bool shouldClose() const = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual float getAspectRatio() const = 0;

    virtual void clear() const = 0;
    virtual void update() = 0;
};
