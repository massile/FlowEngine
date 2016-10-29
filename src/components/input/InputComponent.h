#pragma once

#include <GL/glew.h>

class Camera;
class InputComponent
{
private:
    GLfloat m_sensitivity = 5.0f;
public:
    void update(Camera& camera, float dt);
};