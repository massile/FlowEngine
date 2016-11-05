#pragma once

#include "IKeyboard.h"

class NullKeyboard : public IKeyboard
{
public:
    bool isKeyPressed(int key) const override { return false; }
};

