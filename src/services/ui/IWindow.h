#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#define MAX_KEYS 500
#define MAX_BUTTONS 8

class IWindow
{
public:
    virtual ~IWindow() {}

    virtual bool shouldClose() const = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    virtual void clear() const = 0;
    virtual void update() = 0;

    virtual bool isKeyPressed(int key) const = 0;
    virtual bool isMouseButtonPressed(int button) const = 0;
    virtual glm::vec2 getCursorPosition() const = 0;
    virtual glm::vec2 getCursorPositionOffset() const = 0;
};
