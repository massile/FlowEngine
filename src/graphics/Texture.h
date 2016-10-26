#pragma once

#include <GL/glew.h>
#include <string>
#include "Shader.h"

class Texture
{
private:
    GLuint m_textureId;
    std::string m_name;

public:
    Texture(const std::string& name);
    Texture(const std::string& name, const std::string& filename);
    ~Texture();

    void load(const std::string& filename, const std::string& name);
    void use(Shader& shader) const;
};
