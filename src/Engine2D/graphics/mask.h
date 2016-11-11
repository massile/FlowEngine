#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "texture.h"

namespace FlowEngine { namespace Graphics {
    using namespace glm;
    struct Mask
    {
        Texture* texture;
        glm::mat4 transform;

        Mask(Texture* texture, const mat4& transform = mat4(1.0))
            : texture(texture),
              transform(scale(mat4(), vec3((float)texture->getWidth()/texture->getHeight(), 1.0f, 1.0f)))
        {

        }
    };

}}
