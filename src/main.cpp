#include <iostream>
#include "ui/Window.h"
#include "graphics/Shader.h"
#include "graphics/Mesh.h"

int main()
{
    Window window("OpenGL", 800, 800);
    std::vector<Vertex> vertices = {
        {{-0.5, 0.0, 0.5}},
        {{ 0.0, 0.5, 0.5}},
        {{ 0.5, 0.0, 0.5}}
    };
    std::vector<GLuint> indices = {0, 1, 2};
    Mesh mesh = Mesh(vertices, indices);
    Shader shader = Shader("/home/tessellator/ClionProjects/FlowEngine/resources/shaders/basic.vert",
                           "/home/tessellator/ClionProjects/FlowEngine/resources/shaders/basic.frag");
    float lastTime = 0;
    while(!window.shouldClose()) {
        window.clear();
        if(lastTime) {
            mesh.draw(shader);
            window.update(glfwGetTime() - lastTime);
        }
        lastTime = glfwGetTime();
    }

 	return 0;
}