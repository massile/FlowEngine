#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/renderable2d.h"
#include "graphics/sprite.h"
#include "graphics/batchRenderer2d.h"
#include "graphics/layers/tileLayer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <time.h>

int main()
{
    using namespace FlowEngine;
    using namespace Graphics;
    using namespace glm;

    Window window("OpenGL", 400, 400*9/16);
    srand(time(NULL));

    Shader shader1("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");
    shader1.enable();
    shader1.uniform("pr_matrix", ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));

    TileLayer layer1(&shader1);
    for (float y = -9.0f; y < 9.0f; y += 0.1) {
        for (float x = -16.0f; x < 16.0f; x += 0.1) {
            layer1.add(new Sprite(x, y, 0.09f, 0.09f, vec4(0.5, rand() % 1000 / 1000.0f, 1, 1)));
        }
    }

    Shader shader2("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");
    shader2.enable();
    shader2.uniform("pr_matrix", ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));
    shader2.uniform("light_pos", vec2(-1, 1));

    TileLayer layer2(&shader2);
    layer2.add(new Sprite(-2, -2, 4, 4, vec4(1, 0, 1, 1)));

    float timer = 0.0f, start = glfwGetTime(), elapsed = 0.0f;
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