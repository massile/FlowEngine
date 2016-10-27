#pragma once

#include <glm/glm.hpp>
#include "Shader.h"
#include "../ui/Window.h"

class Light
{
private:
    glm::vec3 m_position;

public:
    Light(const glm::vec3& position);
    void update(Shader& shader);
    void processInput(const Window& window, float dt);
};
