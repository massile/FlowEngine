#pragma once

#include <map>
#include "../../../graphics/Mesh.h"
#include "../../../parse/ObjParser.h"

#define ROOT_DIR std::string("/home/tessellator/ClionProjects/FlowEngine")

class World
{
private:
    std::map<std::string, Mesh*> m_meshes;

public:
    World() {
        m_meshes["rock"] = ObjParser(ROOT_DIR + "/resources/meshes/sphere.obj").parse();
    }

    Mesh* getRock() { return m_meshes["rock"]; }
};