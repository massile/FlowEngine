#include <glm/gtc/matrix_transform.hpp>
#include "PostEffectPass.h"

namespace FlowEngine { namespace Graphics {

    PostEffectPass::PostEffectPass(Shader *shader)
        : mShader(shader)
    {
        mShader->enable();
        mShader->uniform("tex", 0);
        mShader->disable();
    }

    PostEffectPass::~PostEffectPass() {}

    void PostEffectPass::render(FrameBuffer *target)
    {
        mShader->enable();
        mShader->uniform("pr_matrix", glm::ortho(0.0f, (float)target->getWidth(), (float)target->getHeight(), 0.0f, -1.0f, 1.0f));
        API::drawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        mShader->disable();
    }

}}
