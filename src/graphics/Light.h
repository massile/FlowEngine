#pragma once

#include <glm/glm.hpp>
#include "Shader.h"

class Light
{
private:
    glm::vec3 m_position;

public:
    Light(const glm::vec3& position);
    void update(Shader& shader);
};
