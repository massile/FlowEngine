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
        double x, y;
        window.getMousePosition(x, y);
        std::cout << x << ", " << y << std::endl;

        window.update();
    }

    return 0;
}