#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include "../utils/FileParser.h"
#include "../api/API.h"

namespace FlowEngine { namespace Graphics {

    class Shader
    {
    private:
        GLuint mShaderID;
        const std::string& mVertPath;
        const std::string& mFragPath;
    public:
        Shader(const std::string& vertPath, const std::string& fragPath);
        ~Shader();

        void uniform(const char* name, float value);
        void uniform(const char* name, int value);
        void uniform(const char* name, const glm::vec2& vector);
        void uniform(const char* name, const glm::vec3& vector);
        void uniform(const char* name, const glm::vec4& vector);
        void uniform(const char* name, const glm::mat4& matrix);

        void enable() const;
        void disable() const;

        void uniform(const char* name, int* value, int count);

    private:
        uint load();
        int getUniformLocation(const char* name);
    };

}}
