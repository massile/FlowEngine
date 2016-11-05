#include "Provider.h"

Provider::Provider(window *window)
{
    Ui::provide(window);
    Input::provide(new Keyboard(), new Mouse());
}

void Provider::registerCamera(Camera *camera)
{
    m_camera = camera;
}

void Provider::registerLight(Light &light)
{
    m_lights.push_back(light);
}

void Provider::registerPerFrame(Object &object)
{
    m_perFrame.push_back(object);
}

void Provider::registerPerUpdate(Object &object)
{
    m_perUpdate.push_back(object);
}

void Provider::run(Shader &shader)
{
    float lastTime = 0;
    IWindow* window = Ui::getWindow();

    while(!window->shouldClose()) {
        window->clear();

        for(Object& obj : m_perFrame)
            obj.update(shader, 0);

        if(lastTime) {
            float dt = glfwGetTime() - lastTime;
            m_camera->update(shader, dt);
            for(Light& light : m_lights) light.update(shader, dt);
            window->update();
        }

        Input::getMouse()->update();
        lastTime = glfwGetTime();
    }
}
