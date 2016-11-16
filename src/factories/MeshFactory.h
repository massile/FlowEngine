#pragma once

#include <GL/glew.h>
#include "../api/API.h"
#include "../graphics/buffer/VertexArray.h"
#include "../graphics/Mesh.h"

namespace FlowEngine { namespace Graphics {

    namespace MeshFactory
    {
        VertexArray* generateQuad(float x, float y, float width, float height);
        Mesh* generateCube(float size);
    };

}}
