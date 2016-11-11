#include <SOIL/SOIL.h>
#include "texture.h"

namespace FlowEngine { namespace Graphics {

    TextureWrap Texture::sWrapMode;

    Texture::Texture(const std::string& name, const std::string &filename)
            : mFilename(filename), mName(name)
    {
        load();
    }

    Texture::~Texture()
    {
        if(mID) {
            glDeleteTextures(1, &mID);
        }
    }

    void Texture::bind() const
    {
        glBindTexture(GL_TEXTURE_2D, mID);
    }

    GLuint Texture::load()
    {
        unsigned char* pixels = SOIL_load_image(mFilename.c_str(), &mWidth, &mHeight, nullptr, 0);
        glGenTextures(1, &mID);
        bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sWrapMode);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, sWrapMode);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
        SOIL_free_image_data(pixels);
        unbind();
    }

    void Texture::unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}}
