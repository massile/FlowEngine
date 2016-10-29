#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include "../services/ui/window/Window.h"

using namespace glm;

class Camera
{
private:
    mat4 m_view = mat4();
    mat4 m_projection = mat4();

    vec3 m_position = vec3(0.0f, 0.0f, -1.0f);
    vec3 m_front = vec3(0.0f, 0.0f, 1.0f);
    vec3 m_up = vec3(0.0f, 1.0f, 0.0f);
    vec3 m_translate = vec3(0.0f, 0.0f, 0.0f);

    GLfloat m_yaw = 90.0f;
    GLfloat m_pitch = 0.0f;
    GLfloat m_sensitivity = 5.0f;

public:
    Camera(const vec3& position, GLfloat windowRatio);
    ~Camera();

    void update(Shader& shader);
    void processInput(float dt);

    inline glm::vec3 getPosition() const { return m_position; }

private:
    void processKeyboardInput(float dt);
    void processCursorInput(float dt);
};
