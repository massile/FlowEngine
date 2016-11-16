#include <SOIL/SOIL.h>
#include "Texture.h"

namespace FlowEngine { namespace Graphics {

    TextureWrap Texture::sWrapMode;

    Texture::Texture(const std::string& name, const std::string &filename)
            : mFilename(filename), mName(name)
    {
        load();
    }

    Texture::Texture(int width, int height)
        : mWidth(width), mHeight(height)
    {
        load();
    }

    Texture::~Texture()
    {
        if(mID)
            API::freeTexture(mID);
    }

    void Texture::bind() const
    {
        API::bindTexture(GL_TEXTURE_2D, mID);
    }

    GLuint Texture::load()
    {
        unsigned char* pixels = nullptr;
        if(mFilename != "")
            pixels = SOIL_load_image(mFilename.c_str(), &mWidth, &mHeight, nullptr, 0);
        mID = API::createTexture();
        bind();
        API::setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        API::setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        API::setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sWrapMode);
        API::setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, sWrapMode);
        API::setTextureData(GL_TEXTURE_2D, mWidth, mHeight, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, pixels);
        unbind();
        if(mFilename != "")
            SOIL_free_image_data(pixels);
    }

    void Texture::unbind() const
    {
        API::unbindTextures(GL_TEXTURE_2D);
    }

}}
