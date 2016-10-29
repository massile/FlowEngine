#pragma once

#include <glm/glm.hpp>
#include "Shader.h"
#include "../services/ui/window/Window.h"

class Light
{
private:
    glm::vec3 m_position;

public:
    Light(const glm::vec3& position);
    void update(Shader& shader);
    void processInput(float dt);

    inline glm::vec3 getPosition() const { return m_position; }
};
