#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "../../services/ui/Ui.h"
#include "../../graphics/Shader.h"

class Camera;
class ShaderComponent
{
private:
    glm::mat4 m_projection = glm::perspective(45.0f, Ui::getWindow()->getAspectRatio(), 0.1f, 100.0f);

public:
    void update(Camera& camera, Shader& shader);
};