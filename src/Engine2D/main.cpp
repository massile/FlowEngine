#include "graphics/window.h"

int main()
{
    using namespace FlowEngine;
    using namespace Graphics;

    Window window("Sparky!", 960, 540);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    while (!window.closed())
    {
        window.clear();
        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
        window.update();
    }

    return 0;
}