#include <iostream>
#include "ui/Window.h"
#include "graphics/Shader.h"

int main()
{
    Window window("OpenGL", 800, 800);
    Shader shader = Shader("/home/tessellator/ClionProjects/FlowEngine/resources/shaders/basic.vert",
                           "/home/tessellator/ClionProjects/FlowEngine/resources/shaders/basic.frag");
    shader.use();

    float lastTime = 0;
    while(!window.shouldClose()) {
        window.clear();
        if(lastTime) {
            window.update(glfwGetTime() - lastTime);
        }
        lastTime = glfwGetTime();
    }

 	return 0;
}