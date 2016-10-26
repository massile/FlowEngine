#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include "Shader.h"
#include "../ui/Window.h"

using namespace glm;

class Camera
{
private:
    mat4 m_view = mat4();
    mat4 m_projection = mat4();

    vec3 m_position = vec3(0.0f, 0.0f, -1.0f);
    vec3 m_front = vec3(0.0f, 0.0f, 1.0f);
    vec3 m_up = vec3(0.0f, 1.0f, 0.0f);

    GLfloat m_yaw = 90.0f;
    GLfloat m_pitch = 0.0f;
    GLfloat m_sensitivity = 5.0f;

public:
    Camera(const vec3& position, GLfloat windowRatio);
    ~Camera();

    void update(Shader& shader);
    void processInput(const Window& window, float dt);

private:
    void processKeyboardInput(const Window &window, float dt);
    void processCursorInput(const Window& window, float dt);
};
