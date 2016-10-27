#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include "Texture.h"

struct Vertex
{
    glm::vec3 position;
    glm::vec2 uv;
    glm::vec3 normal;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};

class Mesh
{
private:
    std::vector<Vertex> m_vertices;
    std::vector<GLuint> m_indices;
    GLuint m_vertexArrayObjectId;
    GLuint m_vbo;
    GLuint m_ebo;

    glm::mat4 m_modelMatrix = glm::mat4x4();
    Texture* m_diffuseMap = nullptr;
    Texture* m_specularMap = nullptr;
    Texture* m_normalMap = nullptr;

public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
    Mesh(Texture* diffuse, const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
    ~Mesh();

    void draw(Shader& shader);

    inline void setDiffuseTexture(Texture *texture)
    {
        if(texture->getType() != Texture::DIFFUSE)
            throw "Wrong type of texture, should be a diffuse map";
        m_diffuseMap = texture;
    }
    inline void setSpecularTexture(Texture *texture)
    {
        if(texture->getType() != Texture::SPECULAR_MAP)
            throw "Wrong type of texture, should be a specular map";
        m_specularMap = texture;
    }
    inline void setNormalTexture(Texture *texture)
    {
        if(texture->getType() != Texture::NORMAL_MAP)
            throw "Wrong type of texture, should be a normal map";
        m_normalMap = texture;
    }

    inline Texture* getDiffuseTexture() const { return m_diffuseMap; }
    inline Texture* getSpecularTexture() const { return m_specularMap; }
    inline Texture* getNormalTexture() const { return m_normalMap; }
};
