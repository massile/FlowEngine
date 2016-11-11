#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include "../utils/fileutils.h"

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

        void uniform(const GLchar* name, float value);
        void uniform(const GLchar* name, int value);
        void uniform(const GLchar* name, const glm::vec2& vector);
        void uniform(const GLchar* name, const glm::vec3& vector);
        void uniform(const GLchar* name, const glm::vec4& vector);
        void uniform(const GLchar* name, const glm::mat4& matrix);

        void enable() const;
        void disable() const;

        void uniform(const GLchar* name, int* value, int count);

    private:
        GLuint load();
        GLint getUniformLocation(const GLchar* name);
    };

}}
