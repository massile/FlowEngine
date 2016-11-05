#pragma once

#include "../services/input/mouse/Mouse.h"
#include "../services/input/keyboard/Keyboard.h"
#include "../services/input/Input.h"
#include "../services/ui/window/Window.h"
#include "../services/ui/Ui.h"
#include "../graphics/Object.h"
#include "../services/environment/Environment.h"
#include "../graphics/Camera.h"
#include "../graphics/Light.h"

class Provider
{
private:
    std::vector<Object> m_perFrame;
    std::vector<Object> m_perUpdate;
    std::vector<Light> m_lights;
    Camera* m_camera;

public:
    Provider(window* window);

    virtual void record() = 0;

    void registerCamera(Camera* camera);
    void registerLight(Light& light);
    void registerPerFrame(Object& object);
    void registerPerUpdate(Object& object);

    void run(Shader& shader);

};