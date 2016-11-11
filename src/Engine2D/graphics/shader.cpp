#include "shader.h"
#include <glm/gtc/type_ptr.hpp>

namespace FlowEngine { namespace Graphics {

    Shader::Shader(const std::string& vertPath, const std::string& fragPath)
            : mVertPath(vertPath), mFragPath(fragPath)
    {
        mShaderID = load();
    }

    Shader::~Shader()
    {
        glDeleteProgram(mShaderID);
    }

    GLuint Shader::load()
    {
        GLuint program = glCreateProgram();
        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertSourceString = FileUtils::read_file(mVertPath.c_str());
        std::string fragSourceString = FileUtils::read_file(mFragPath.c_str());

        const char* vertSource = vertSourceString.c_str();
        const char* fragSource = fragSourceString.c_str();

        glShaderSource(vertex, 1, &vertSource, NULL);
        glCompileShader(vertex);

        GLint result;
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            GLint length;
            glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
            std::vector<char> error(length);
            glGetShaderInfoLog(vertex, length, &length, &error[0]);
            std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
            glDeleteShader(vertex);
            return 0;
        }

        glShaderSource(fragment, 1, &fragSource, NULL);
        glCompileShader(fragment);

        glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            GLint length;
            glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
            std::vector<char> error(length);
            glGetShaderInfoLog(fragment, length, &length, &error[0]);
            std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
            glDeleteShader(fragment);
            return 0;
        }

        glAttachShader(program, vertex);
        glAttachShader(program, fragment);

        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        return program;
    }

    GLint Shader::getUniformLocation(const GLchar* name)
    {
        return glGetUniformLocation(mShaderID, name);
    }

    void Shader::uniform(const GLchar* name, float value)
    {
        glUniform1f(getUniformLocation(name), value);
    }

    void Shader::uniform(const GLchar* name, int value)
    {
        glUniform1i(getUniformLocation(name), value);
    }

    void Shader::uniform(const GLchar* name, const glm::vec2& vector)
    {
        glUniform2f(getUniformLocation(name), vector.x, vector.y);
    }

    void Shader::uniform(const GLchar* name, const glm::vec3& vector)
    {
        glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
    }

    void Shader::uniform(const GLchar* name, const glm::vec4& vector)
    {
        glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
    }

    void Shader::uniform(const GLchar* name, const glm::mat4& matrix)
    {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void Shader::enable() const
    {
        glUseProgram(mShaderID);
    }

    void Shader::disable() const
    {
        glUseProgram(0);
    }

    void Shader::uniform(const GLchar* name, int* value, int count)
    {
        glUniform1iv(getUniformLocation(name), count, value);
    }
}}