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
    Texture m_texture;

public:
    Mesh(const Texture& texture, const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
    ~Mesh();

    void draw(Shader& shader);
};
