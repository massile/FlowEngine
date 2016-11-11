#pragma once

#include <vector>
#include "texture.h"

namespace FlowEngine { namespace Graphics {

    class TextureManager
    {
    private:
        static std::vector<Texture*> mTextures;

    public:
        static void add(Texture* texture);
        static Texture* get(const std::string& name);
        static void clean();

    private:
        TextureManager() {}
    };

}}
