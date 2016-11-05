#include "Texture.h"
#include <SOIL/SOIL.h>

Texture::Texture(const std::string& name, const Type type)
        : m_name(name), m_type(type)
{
    glGenTextures(1, &m_textureId);
}

Texture::Texture(const std::string& name, const std::string &filename, const Type type)
        : Texture(name, type)
{
    load(filename, m_name);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_textureId);
}

void Texture::load(const std::string &filename, const std::string& name)
{
    glBindTexture(GL_TEXTURE_2D, m_textureId);

    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height;
    unsigned char* pixels = SOIL_load_image(filename.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::use(Shader& shader) const
{
    glActiveTexture(m_type);
    glBindTexture(GL_TEXTURE_2D, m_textureId);
    shader.uniform(m_name, m_type - GL_TEXTURE0);
}


