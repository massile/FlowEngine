#pragma once

#include "../../../graphics/Mesh.h"
#include "../../../graphics/Texture.h"

class IWorld {
private:
    std::map<std::string, Mesh*> m_meshes;
    std::map<std::string, Shader*> m_shaders;
    std::map<std::string, TextureMap*> m_textures;

public:
    Mesh* getMesh(const std::string& name) { return m_meshes[name]; }
    TextureMap* getTexture(const std::string& name) { return m_textures[name]; }
    Shader* getShader(const std::string& name) { return m_shaders[name]; }

    void record(const std::string& name, Mesh* mesh) { m_meshes[name] = mesh; }
    void record(const std::string& name, TextureMap* texture) { m_textures[name] = texture; }
    void record(const std::string& name, Shader* shader) { m_shaders[name] = shader; }
};