#pragma once

#include "../renderable2d.h"
#include "../renderer2d.h"

namespace FlowEngine { namespace Graphics {
    class Group : public Renderable2D
    {
    private:
        std::vector<Renderable2D*> m_Renderables;
        glm::mat4 m_TransformationMatrix;
    public:
        Group(const glm::mat4& transform);
        void add(Renderable2D* renderable);
        void submit(Renderer2D* renderer) const override;
    };
}}