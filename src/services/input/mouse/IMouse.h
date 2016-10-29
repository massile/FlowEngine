#pragma once

#include <glm/vec2.hpp>

#define MAX_BUTTONS 8

class IMouse
{
public:
    virtual bool isMouseButtonPressed(int button) const = 0;
    virtual void update() = 0;
    virtual glm::vec2 getCursorPosition() const = 0;
    virtual glm::vec2 getCursorPositionOffset() const = 0;
};