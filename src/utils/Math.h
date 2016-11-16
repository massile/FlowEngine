#pragma once

#include <glm/glm.hpp>

namespace glm {
    vec3 operator*(mat4 matrix, vec3 vector) {
        return vec3(matrix * vec4(vector, 1.0f));
    }
}