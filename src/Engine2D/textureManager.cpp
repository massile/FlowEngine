#include "textureManager.h"

namespace FlowEngine { namespace Graphics {

    std::vector<Texture*> mTextures;

    void TextureManager::add(FlowEngine::Graphics::Texture *texture)
    {
        mTextures.push_back(texture);
    }

    Texture *TextureManager::get(const std::string &name)
    {
        for(Texture* texture: mTextures) {
            if(texture->getName() == name) {
                return texture;
            }
        }
        return nullptr;
    }

    void TextureManager::clean()
    {
        for(int i=0; i<mTextures.size(); i++) {
            delete mTextures[i];
        }
    }

}}

