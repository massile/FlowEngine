#pragma once

#include <glm/glm.hpp>
#include "../api/API.h"

namespace FlowEngine { namespace Graphics {

    struct Vertex2D
    {
        glm::vec3 position;
        uint color;
        glm::vec2 uv;
        glm::vec2 maskUv;
        float tid;
        float mid;
    };

    struct Vertex3D
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uv;
    };

}}