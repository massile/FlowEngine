#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include "Shader.h"

class Camera
{
private:
    glm::mat4 m_view = glm::mat4();
    glm::mat4 m_projection = glm::mat4();

public:
    Camera(const glm::vec3& position, GLfloat windowRatio);
    ~Camera();

    void update(Shader& shader);
};
