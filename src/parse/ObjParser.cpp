#include <fstream>
#include <regex>
#include <iostream>
#include "ObjParser.h"

ObjParser::ObjParser(const std::string &filepath)
        : Parser(filepath, FileFormat::OBJ)
{}

Mesh ObjParser::parse()
{
    std::ifstream file(m_filepath);
    std::string val;
    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    int index = 0;
    while(file >> val) {
        if(val == "v") {
            glm::vec3 position;
            file >> position.x >> position.y >> position.z;
            positions.push_back(position);
        } else if(val == "vt") {
            glm::vec2 uv;
            file >> uv.s >> uv.t;
            uvs.push_back(uv);
        } else if(val == "vn") {
            glm::vec3 normal;
            file >> normal.x >> normal.y >> normal.z;
            normals.push_back(normal);
        } else if(val == "f") {
            char slash;
            for(int i=0; i<3; i++) {
                Vertex v;
                GLuint positionId, uvId, normalId;
                file >> positionId >> slash >> uvId >> slash >> normalId;
                v.position = positions[positionId - 1];
                v.uv = uvs[uvId - 1];
                v.normal = normals[normalId - 1];

                indices.push_back(index++);
                vertices.push_back(v);
            }
        }

        std::getline(file, val);
    }
    generateTangentSpace(vertices);

    return Mesh(vertices, indices);
}

ObjParser::~ObjParser()
{}

void ObjParser::generateTangentSpace(std::vector<Vertex> &vertices)
{
    for ( int i=0; i < vertices.size(); i += 3) {
        Vertex v0 = vertices[i];
        Vertex v1 = vertices[i + 1];
        Vertex v2 = vertices[i + 2];

        glm::vec3 deltaPos1 = v1.position - v0.position;
        glm::vec3 deltaPos2 = v2.position - v0.position;

        glm::vec2 deltaUV1 = v1.uv - v0.uv;
        glm::vec2 deltaUV2 = v2.uv - v0.uv;

        float r = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);
        glm::vec3 tangent = (deltaPos1 * deltaUV2.y   - deltaPos2 * deltaUV1.y)*r;
        glm::vec3 bitangent = (deltaPos2 * deltaUV1.x   - deltaPos1 * deltaUV2.x)*r;

        for(int j=0; j<3; j++) {
            vertices[i + j].tangent = tangent;
            vertices[i + j].bitangent = bitangent;
        }
    }
}
