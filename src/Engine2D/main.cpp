#include "graphics/window.h"
#include "graphics/shader.h"
#include <glm/gtc/matrix_transform.hpp>

int main()
{
    using namespace FlowEngine;
    using namespace Graphics;
    using namespace glm;

    Window window("OpenGL", 960, 540);

    GLfloat vertices[] = {
        0, 0, 0,
        8, 0, 0,
        0, 3, 0,
        0, 3, 0,
        8, 3, 0,
        8, 0, 0
    };

    GLuint vbo, vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    Shader shader("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");
    shader.enable();
    shader.uniform("pr_matrix", ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));
    shader.uniform("ml_matrix", translate(mat4(), vec3(4, 3, 0)));

    shader.uniform("light_pos", vec2(4.0f, 1.5f));
    shader.uniform("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

    while (!window.closed())
    {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);
        shader.uniform("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
        glDrawArrays(GL_TRIANGLES, 0, 6);
        window.update();
    }

    return 0;
}