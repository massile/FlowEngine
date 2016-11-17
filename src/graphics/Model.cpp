#include <iostream>
#include "Model.h"
#include "../utils/String.h"
#include "../utils/FileParser.h"
#include "Vertex.h"

namespace FlowEngine { namespace Graphics {

    Model::Model(const std::string &filename) : mFilename(filename)
    {
        using namespace std;

        vector<glm::vec3> inputPositions, inputNormals;
        vector<glm::vec2> inputUvs;

        vector<Vertex3D> vertices;
        vector<uint> indices;

        string fileContent = FileParser::readFile(mFilename);
        vector<string> lines = String::split(fileContent, '\n');
        for(string& line : lines) {
            const char* cline = line.c_str();
            if(strstr(cline, "vt")) {
                glm::vec2 uv;
                if(sscanf(cline, "vt %f %f", &uv.x, &uv.y))
                    inputUvs.push_back(uv);
            }
            else if(strstr(cline, "vn")) {
                glm::vec3 normal;
                if(sscanf(cline, "vn %f %f %f", &normal.x, &normal.y, &normal.z))
                    inputNormals.push_back(normal);
            }
            else if(strstr(cline, "v")) {
                glm::vec3 position;
                if(sscanf(cline, "v %f %f %f", &position.x, &position.y, &position.z))
                    inputPositions.push_back(position);
            }
            else if(strstr(cline, "f")) {
                glm::tvec3<int> posIndices, normIndices, uvIndices;
                if(sscanf(cline, "f %d/%d/%d %d/%d/%d %d/%d/%d",
                          &posIndices.x, &uvIndices.x, &normIndices.x,
                          &posIndices.y, &uvIndices.y, &normIndices.y,
                          &posIndices.z, &uvIndices.z, &normIndices.z))
                    for (int i = 0; i < 3; i++) {
                        indices.push_back(vertices.size());
                        vertices.push_back({inputPositions[posIndices[i] - 1],
                                            inputNormals[normIndices[i] - 1],
                                            inputUvs[uvIndices[i] - 1]});
                    }
            }
        }
        inputNormals.clear();
        inputPositions.clear();
        inputUvs.clear();

        VertexBuffer buffer(GL_ARRAY_BUFFER, GL_DYNAMIC_DRAW);
        buffer.setData(vertices.size() * sizeof(Vertex3D), vertices.data());
        buffer.setAttribute<glm::vec3>(POSITION);
        buffer.setAttribute<glm::vec3>(NORMAL);
        buffer.setAttribute<glm::vec2>(UV);

        VertexArray* vertexArray = new VertexArray;
        vertexArray->addBuffer(&buffer);

        mMesh = new Mesh(vertexArray, new IndexBuffer(indices));
    }

    void Model::render(Graphics::Renderer3D &renderer) const
    {
        mMesh->render(renderer);
    }

}}
