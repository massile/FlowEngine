#include "ForwardRenderer.h"

namespace FlowEngine { namespace Graphics {

    void ForwardRenderer::begin()
    {
        mDrawQueue.clear();
    }

    void ForwardRenderer::submit(const Mesh* renderable)
    {
        mDrawQueue.push_back(renderable);
    }

    void ForwardRenderer::flush()
    {
        for(const Mesh* mesh: mDrawQueue)
            mesh->render(*this);
    }

    void ForwardRenderer::end()
    {

    }

}}
