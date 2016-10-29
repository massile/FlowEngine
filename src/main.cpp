#include <iostream>

#include "services/ui/Ui.h"
#include "services/ui/window/Window.h"
#include "services/input/keyboard/Keyboard.h"
#include "services/input/mouse/Mouse.h"
#include "services/input/Input.h"

#include "graphics/Shader.h"
#include "graphics/Mesh.h"
#include "graphics/Camera.h"
#include "graphics/Light.h"

#include "parse/ObjParser.h"

#define ROOT_DIR std::string("/home/tessellator/ClionProjects/FlowEngine")

int main()
{
    IWindow* win = new Window("OpenGL", 1000, 1000);
    IKeyboard* keyboard = new Keyboard();
    IMouse* mouse = new Mouse();

    Ui::provide(win);
    Input::provide(keyboard, mouse);

    IWindow* window = Ui::getWindow();

    Shader shader = Shader(ROOT_DIR + "/resources/shaders/basic.vert", ROOT_DIR + "/resources/shaders/basic.frag");
    Mesh mesh = ObjParser(ROOT_DIR + "/resources/meshes/sphere.obj").parse();
    mesh.setDiffuseTexture(new Texture("diffuseMap", ROOT_DIR + "/resources/textures/rocks-diffuse.jpg", Texture::DIFFUSE));
    mesh.setSpecularTexture(new Texture("specularMap", ROOT_DIR + "/resources/textures/rocks-spec.jpg", Texture::SPECULAR_MAP));
    mesh.setNormalTexture(new Texture("normalMap", ROOT_DIR + "/resources/textures/rocks-normal.jpg", Texture::NORMAL_MAP));

    Camera camera(glm::vec3(0.8, 1.2, -2), window->getWidth()/window->getHeight());
    Light light(glm::vec3(0, 0, 0));

    float lastTime = 0;
    while(!window->shouldClose()) {
        window->clear();
        mesh.draw(shader);

        if(lastTime) {
            float dt = glfwGetTime() - lastTime;

            if(keyboard->isKeyPressed(GLFW_KEY_KP_8)) {
                mesh.rotate(dt * glm::vec3(0, 0.4f, 0));
            }

            if(keyboard->isKeyPressed(GLFW_KEY_KP_5)) {
                mesh.translate(dt * glm::vec3(0, -1.0f, 0));
            }

            if(keyboard->isKeyPressed(GLFW_KEY_KP_4)) {
                mesh.translate(dt * glm::vec3(1.0f, 0, 0));
            }

            if(keyboard->isKeyPressed(GLFW_KEY_KP_6)) {
                mesh.translate(dt * glm::vec3(-1.0f, 0, 0));
            }

            camera.processInput(dt);
            light.processInput(dt);
            camera.update(shader);
            light.update(shader);
            window->update();
        }

        lastTime = glfwGetTime();
    }

 	return 0;
}