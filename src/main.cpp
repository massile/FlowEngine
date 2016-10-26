#include <iostream>
#include "ui/Window.h"
#include "graphics/Shader.h"
#include "graphics/Mesh.h"
#include "graphics/Texture.h"
#include "graphics/Camera.h"

int main()
{
    Window window("OpenGL", 800, 800);
    std::vector<Vertex> vertices = {
        {{-2, -2, 0}, {0.0, 0.0}},
        {{ 0, 2, 0}, {0.5, 1.0}},
        {{ 2, -2, 0}, {1.0, 0.0}}
    };
    std::vector<GLuint> indices = {0, 1, 2};

    Mesh mesh = Mesh(vertices, indices);
    Shader shader = Shader("/home/tessellator/ClionProjects/FlowEngine/resources/shaders/basic.vert",
                           "/home/tessellator/ClionProjects/FlowEngine/resources/shaders/basic.frag");
    Texture texture("tex", "/home/tessellator/ClionProjects/FlowEngine/resources/textures/floor.png");

    Camera camera(glm::vec3(-5, 5, -5), window.getWidth()/window.getHeight());

    shader.use();
    texture.use(shader);

    float lastTime = 0;
    while(!window.shouldClose()) {
        window.clear();
        mesh.draw(shader);
        if(lastTime) {
            camera.update(shader);
            window.update(glfwGetTime() - lastTime);
        }
        lastTime = glfwGetTime();
    }

 	return 0;
}