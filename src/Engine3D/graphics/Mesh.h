#pragma once

#include <GL/glew.h>
#include <vector>
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

typedef GLuint Index;
typedef std::vector<Vertex> Vertices;
typedef std::vector<Index> Indices;

class Mesh
{
private:
    Vertices m_vertices;
    Indices m_indices;
    GLuint m_vertexArrayObjectId;
    GLuint m_vbo;
    GLuint m_ebo;

public:
    Mesh(const Vertices& vertices, const Indices& indices);
    ~Mesh();

    void draw();
};
