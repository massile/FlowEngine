#pragma once

#include "Provider.h"

class AppProvider : public Provider
{
public:
    AppProvider() : Provider(new Window("OpenGL", 1000, 1000)) {}
    virtual void record() override;
};