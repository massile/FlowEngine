#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "texture.h"

namespace FlowEngine { namespace Graphics {
    struct Mask
    {
        Texture* texture;
        glm::mat4 transform;

        Mask(Texture* texture, const glm::mat4& transform = glm::mat4(1.0))
            : texture(texture),
              transform(glm::scale(glm::mat4(), glm::vec3((float)texture->getWidth()/texture->getHeight(), 1.0f, 1.0f)))
        {

        }
    };

}}
