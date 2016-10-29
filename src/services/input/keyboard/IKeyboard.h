#pragma once

#define MAX_KEYS 500

class IKeyboard
{
public:
    virtual bool isKeyPressed(int key) const = 0;
};