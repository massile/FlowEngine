#include <iostream>
#include "ui/Window.h"
#include "graphics/Shader.h"
#include "graphics/Mesh.h"
#include "graphics/Camera.h"
#include "parse/ObjParser.h"
#include "graphics/Light.h"

#define ROOT_DIR std::string("/home/tessellator/ClionProjects/FlowEngine")

int main()
{
    Window window("OpenGL", 400, 400);

    Shader shader = Shader(ROOT_DIR + "/resources/shaders/basic.vert", ROOT_DIR + "/resources/shaders/basic.frag");
    Mesh mesh = ObjParser(ROOT_DIR + "/resources/meshes/sphere.obj").parse();
    Camera camera(glm::vec3(0, 0, -5), window.getWidth()/window.getHeight());
    Light light(glm::vec3(0, 100, 100));

    float lastTime = 0;
    while(!window.shouldClose()) {
        window.clear();
        mesh.draw(shader);

        if(lastTime) {
            float dt = glfwGetTime() - lastTime;

            camera.processInput(window, dt);
            camera.update(shader);
            light.update(shader);
            window.update();
        }

        lastTime = glfwGetTime();
    }

 	return 0;
}