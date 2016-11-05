#pragma once

#include <GL/glew.h>
#include <string>
#include "Shader.h"

typedef int Type;

class Texture
{
public:
    static const Type DIFFUSE = GL_TEXTURE0;
    static const Type SPECULAR_MAP  = GL_TEXTURE1;
    static const Type NORMAL_MAP  = GL_TEXTURE2;

private:
    GLuint m_textureId;
    Type m_type;
    std::string m_name;

public:
    Texture(const std::string& name, const Type type = DIFFUSE);
    Texture(const std::string& name, const std::string& filename, const Type type = DIFFUSE);
    ~Texture();

    void load(const std::string& filename, const std::string& name);
    void use(Shader& shader) const;

    inline Type getType() const { return m_type; }
};

struct TextureMap {
    Texture* diffuse;
    Texture* specular;
    Texture* normal;

    TextureMap(Texture* diff, Texture* spec, Texture* norm)
            : diffuse(diff), specular(spec), normal(norm) {}

    void use(Shader& shader) {
        diffuse->use(shader);
        specular->use(shader);
        normal->use(shader);
    }
};
