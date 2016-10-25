#include <vector>
#include <iostream>
#include "Shader.h"
#include "../parse/File.h"

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath)
{
    std::string vsSource = File(vertexPath).getContents();
    std::string fsSource = File(fragmentPath).getContents();

    GLuint vertexShaderId = compile(vsSource.c_str(), GL_VERTEX_SHADER, vertexPath);
    GLuint fragmentShaderId = compile(fsSource.c_str(), GL_FRAGMENT_SHADER, fragmentPath);

    link(vertexShaderId, fragmentShaderId);

    glDetachShader(m_id, vertexShaderId);
    glDetachShader(m_id, fragmentShaderId);
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
}

Shader::~Shader()
{
    glDeleteProgram(m_id);
}

GLuint Shader::compile(const GLchar *sourceCode, GLenum shaderType, const std::string &filename) {
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &sourceCode, nullptr);
    glCompileShader(shader);

    GLint success;
    GLint length;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> errorStr(length);
        glGetShaderInfoLog(shader, length, nullptr, errorStr.data());
        std::cout << "Error in " << filename << ": " << errorStr.data() << std::endl;
    }

    return shader;
}

void Shader::link(GLuint vertexShader, GLuint fragmentShader) {
    m_id = glCreateProgram();
    glAttachShader(m_id, vertexShader);
    glAttachShader(m_id, fragmentShader);
    glLinkProgram(m_id);

    GLint success;
    GLint length;
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &length);
        std::vector<char> errorStr(length);
        glGetProgramInfoLog(m_id, length, &length, errorStr.data());
        std::cout << "Error on program link: " << errorStr.data() << std::endl;
    }
}
