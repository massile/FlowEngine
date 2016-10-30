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
#include "components/input/CameraInputComponent.h"
#include "components/input/LightInputComponent.h"
#include "components/physics/CameraPhysicsComponent.h"
#include "components/shader/CameraShaderComponent.h"
#include "components/shader/LightShaderComponent.h"

#define ROOT_DIR std::string("/home/tessellator/ClionProjects/FlowEngine")

int main()
{
    IWindow* win = new Window("OpenGL", 1000, 1000);
    Ui::provide(win);

    IKeyboard* keyboard = new Keyboard();
    IMouse* mouse = new Mouse();
    Input::provide(keyboard, mouse);

    IWindow* window = Ui::getWindow();

    Shader shader = Shader(ROOT_DIR + "/resources/shaders/basic.vert", ROOT_DIR + "/resources/shaders/basic.frag");
    Mesh mesh = ObjParser(ROOT_DIR + "/resources/meshes/sphere.obj").parse();
    Texture diffuseMap = Texture("diffuseMap", ROOT_DIR + "/resources/textures/rocks-diffuse.jpg", Texture::DIFFUSE);
    Texture specularMap = Texture("specularMap", ROOT_DIR + "/resources/textures/rocks-spec.jpg", Texture::SPECULAR_MAP);
    Texture normalMap = Texture("normalMap", ROOT_DIR + "/resources/textures/rocks-normal.jpg", Texture::NORMAL_MAP);

    Camera camera(
        new CameraInputComponent(),
        new CameraPhysicsComponent(),
        new CameraShaderComponent()
    );
    Light light(
        new LightInputComponent(),
        nullptr,
        new LightShaderComponent()
    );

    float lastTime = 0;
    while(!window->shouldClose()) {
        window->clear();

        diffuseMap.use(shader);
        specularMap.use(shader);
        normalMap.use(shader);
        mesh.draw();

        if(lastTime) {
            float dt = glfwGetTime() - lastTime;
            camera.update(shader, dt);
            light.update(shader, dt);
            window->update();
        }

        Input::getMouse()->update();
        lastTime = glfwGetTime();
    }

 	return 0;
}