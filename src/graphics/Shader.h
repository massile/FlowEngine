#pragma once

#include <GL/glew.h>
#include <string>

class Shader
{
private:
    GLuint m_id;

public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    inline void use() const { glUseProgram(m_id); }
    inline GLuint getId() const { return m_id; }

private:
    GLuint compile(const GLchar *sourceCode, GLenum shaderType, const std::string &filename);
    void link(GLuint vertexShader, GLuint fragmentShader);

};
