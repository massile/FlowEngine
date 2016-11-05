#pragma once

#include "IMouse.h"
#include "../../ui/window/IWindow.h"

class NullMouse : public IMouse
{
public:
    virtual ~NullMouse() {}

    bool isMouseButtonPressed(int button) const override { return false; }
    glm::vec2 getCursorPosition() const override { return glm::vec2(); }
    glm::vec2 getCursorPositionOffset() const override { return glm::vec2(); }

    void update() override {}
};

