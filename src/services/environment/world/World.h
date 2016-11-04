#pragma once

#include <map>
#include "../../../graphics/Mesh.h"
#include "../../../parse/ObjParser.h"

#define ROOT_DIR std::string("/home/tessellator/ClionProjects/FlowEngine")

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

class World
{

private:
    std::map<std::string, Mesh*> m_meshes;
    std::map<std::string, Shader*> m_shaders;
    std::map<std::string, TextureMap*> m_textures;

public:
    World() {
        m_meshes["rock"] = ObjParser(ROOT_DIR + "/resources/meshes/sphere.obj").parse();
        m_shaders["mesh"] = new Shader(ROOT_DIR + "/resources/shaders/basic.vert", ROOT_DIR + "/resources/shaders/basic.frag");
        m_textures["rocks"] = new TextureMap(
            new Texture("diffuseMap", ROOT_DIR + "/resources/textures/rocks-diffuse.jpg", Texture::DIFFUSE),
            new Texture("specularMap", ROOT_DIR + "/resources/textures/rocks-spec.jpg", Texture::SPECULAR_MAP),
            new Texture("normalMap", ROOT_DIR + "/resources/textures/rocks-normal.jpg", Texture::NORMAL_MAP)
        );
    }

    Mesh* getRock() { return m_meshes["rock"]; }
    TextureMap* getRocksTexture() { return m_textures["rocks"]; }
    Shader* getMeshShader() { return m_shaders["mesh"]; }
};