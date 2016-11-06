#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/renderable2d.h"
#include "graphics/sprite.h"
#include "graphics/batchRenderer2d.h"
#include "graphics/layers/tileLayer.h"
#include "graphics/layers/group.h"
#include <glm/gtc/matrix_transform.hpp>

int main()
{
    using namespace FlowEngine;
    using namespace Graphics;
    using namespace glm;

    Window window("OpenGL", 400, 400*9/16);

    Shader shader1("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");
    shader1.enable();
    shader1.uniform("pr_matrix", ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));

    TileLayer layer1(&shader1);

    Group* group = new Group(translate(mat4(), vec3(-15.0f, 5.0f, 0.0f)));
    group->add(new Sprite(0, 0, 6, 3, vec4(1, 1, 1, 1)));

    Group* button = new Group(translate(mat4(), vec3(0.5f, 0.5f, 0.0f)));
    button->add(new Sprite(0, 0, 5.0f, 2.0f, vec4(1, 0, 1, 1)));
    button->add(new Sprite(0.5f, 0.5f, 3.0f, 1.0f, vec4(0.2f, 0.3f, 0.8f, 1)));
    group->add(button);

    layer1.add(group);

    Shader shader2("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");
    shader2.enable();
    shader2.uniform("pr_matrix", ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));
    shader2.uniform("light_pos", vec2(-1, 1));

    TileLayer layer2(&shader2);
    layer2.add(new Sprite(-2, -2, 4, 4, vec4(1, 0, 1, 1)));

    float timer = 0.0f, start = glfwGetTime(), elapsed;
    unsigned int frames = 0;
    while (!window.closed())
    {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);

        shader1.enable();
        shader1.uniform("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
        layer1.render();

        shader2.enable();
        layer2.render();

        window.update();

        frames++;
        elapsed = glfwGetTime() - start;
        if (elapsed -   timer > 1.0f)
        {
            timer += 1.0f;
            frames = 0;
        }
    }

    return 0;
}