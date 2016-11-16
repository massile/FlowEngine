#include "Scene.h"
#include "renderer3d.h"

namespace FlowEngine { namespace Graphics {

    Scene::Scene()
    {

    }

    Scene::~Scene()
    {
        for(Mesh* mesh : mMeshes)
            delete mesh;
        mMeshes.clear();
    }

    void Scene::add(Mesh *mesh)
    {
        mMeshes.push_back(mesh);
    }

    void Scene::render(Renderer3D &renderer)
    {
        for(Mesh* mesh : mMeshes)
            renderer.submit(mesh);
    }

}}
