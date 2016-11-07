#include <SOIL/SOIL.h>
#include "texture.h"

namespace FlowEngine { namespace Graphics {

    Texture::Texture(const std::string &filename) : m_filename(filename)
    {
        load();
    }

    Texture::~Texture()
    {
        if(m_id) {
            glDeleteTextures(1, &m_id);
        }
    }

    void Texture::bind() const
    {
        glBindTexture(GL_TEXTURE_2D, m_id);
    }

    GLuint Texture::load()
    {

        unsigned char* pixels = SOIL_load_image(m_filename.c_str(), &m_width, &m_height, nullptr, 0);
        glGenTextures(1, &m_id);
        bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);
        SOIL_free_image_data(pixels);
        unbind();
    }

    void Texture::unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}}

