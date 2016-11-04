#pragma once

#include <map>
#include "../../../graphics/Mesh.h"
#include "../../../parse/ObjParser.h"
#include "IWorld.h"

#define ROOT_DIR std::string("/home/tessellator/ClionProjects/FlowEngine")

class World : public IWorld
{
public:
    World() {
        record("rock", ObjParser(ROOT_DIR + "/resources/meshes/sphere.obj").parse());
        record("shader", new Shader(ROOT_DIR + "/resources/shaders/basic.vert", ROOT_DIR + "/resources/shaders/basic.frag"));
        record("rocks", new TextureMap(
            new Texture("diffuseMap", ROOT_DIR + "/resources/textures/rocks-diffuse.jpg", Texture::DIFFUSE),
            new Texture("specularMap", ROOT_DIR + "/resources/textures/rocks-spec.jpg", Texture::SPECULAR_MAP),
            new Texture("normalMap", ROOT_DIR + "/resources/textures/rocks-normal.jpg", Texture::NORMAL_MAP)
        ));
    }
};