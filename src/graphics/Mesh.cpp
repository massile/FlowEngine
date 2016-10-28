#include <glm/gtc/matrix_transform.hpp>
#include "Mesh.h"

#define RESOURCE_DIR std::string("/home/tessellator/ClionProjects/FlowEngine/resources")

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices)
        : m_vertices(vertices),
          m_indices(indices),
          m_diffuseMap(new Texture("tex", RESOURCE_DIR + "/textures/floor.png"))
{
    glGenVertexArrays(1, &m_vertexArrayObjectId);
    glBindVertexArray(m_vertexArrayObjectId);

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
    glEnableVertexAttribArray(3);

    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, bitangent));
    glEnableVertexAttribArray(4);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::Mesh(Texture* diffuse, const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices)
        : Mesh(vertices, indices)
{
    m_diffuseMap = diffuse;
}


Mesh::~Mesh()
{
    m_vertices.clear();
    m_indices.clear();
    glDeleteBuffers(1, &m_ebo);
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vertexArrayObjectId);
}

void Mesh::draw(Shader &shader)
{
    shader.use();
    m_diffuseMap->use(shader);
    m_specularMap->use(shader);
    m_normalMap->use(shader);
    glm::mat4 modelMatrix = glm::translate(glm::mat4(), m_position);
    modelMatrix = glm::rotate(modelMatrix, m_rotation.x, glm::vec3(1, 0, 0));
    modelMatrix = glm::rotate(modelMatrix, m_rotation.y, glm::vec3(0, 1, 0));
    modelMatrix = glm::rotate(modelMatrix, m_rotation.z, glm::vec3(0, 0, 1));

    shader.uniform("model", modelMatrix);
    glBindVertexArray(m_vertexArrayObjectId);
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

void Mesh::translate(glm::vec3 offset)
{
    m_position += offset;
}

void Mesh::rotate(glm::vec3 offset)
{
    m_rotation += offset;
}
