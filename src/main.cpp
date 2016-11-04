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

#include "components/input/CameraInputComponent.h"
#include "components/input/LightInputComponent.h"
#include "components/physics/CameraPhysicsComponent.h"
#include "components/shader/CameraShaderComponent.h"
#include "components/shader/LightShaderComponent.h"
#include "services/environment/Environment.h"
#include "components/graphics/MeshGraphicsComponent.h"

#define ROOT_DIR std::string("/home/tessellator/ClionProjects/FlowEngine")

int main()
{
    IWindow* win = new Window("OpenGL", 1000, 1000);
    Ui::provide(win);

    IKeyboard* keyboard = new Keyboard();
    IMouse* mouse = new Mouse();
    Input::provide(keyboard, mouse);

    Graphics* graphics = new Graphics();
    World* world = new World();
    Environment::provide(world, graphics);

    IWindow* window = Ui::getWindow();

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
    Object rock(
        nullptr,
        nullptr,
        nullptr,
        new MeshGraphicsComponent()
    );

    Shader* shader = Environment::getWorld()->getMeshShader();
    float lastTime = 0;
    while(!window->shouldClose()) {
        window->clear();

        rock.update(*shader, 0);

        if(lastTime) {
            float dt = glfwGetTime() - lastTime;
            camera.update(*shader, dt);
            light.update(*shader, dt);
            window->update();
        }

        Input::getMouse()->update();
        lastTime = glfwGetTime();
    }

 	return 0;
}