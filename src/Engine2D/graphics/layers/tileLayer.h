#pragma once

#include "layer.h"

namespace FlowEngine { namespace Graphics {

    class TileLayer : public Layer
    {
    public:
        TileLayer(Shader* shader);
        ~TileLayer();
    };

} }