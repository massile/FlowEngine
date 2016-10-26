#pragma once

#include <GL/glew.h>
#include <string>
#include <map>

class Shader
{
private:
    std::map<std::string, GLuint> m_uniforms;
    GLuint m_id;

public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void uniform(const std::string& name, int value);

    inline void use() const { glUseProgram(m_id); }
    inline GLuint getId() const { return m_id; }

private:
    GLuint getUniformLocation(const std::string& name);

    GLuint compile(const GLchar *sourceCode, GLenum shaderType, const std::string &filename);
    void link(GLuint vertexShader, GLuint fragmentShader);

};
