#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/renderable2d.h"
#include "graphics/sprite.h"
#include "graphics/layers/tileLayer.h"
#include <glm/gtc/matrix_transform.hpp>

int main()
{
    using namespace FlowEngine;
    using namespace Graphics;
    using namespace glm;

    srand(time(nullptr));

    Window window("OpenGL", 960, 540);

    Shader shader("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");
    shader.enable();
    shader.uniform("pr_matrix", ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));
    shader.uniform("light_pos", vec2(-1, 1));

    Texture* textures[] = {
        new Texture("resources/textures/brick-diffuse.jpg"),
        new Texture("resources/textures/rocks-diffuse.jpg")
    };

    TileLayer layer(&shader);
    for (float y = -9.0f; y < 9.0f; y++) {
        for (float x = -16.0f; x < 16.0f; x++) {
            if (rand() % 4 == 0)
                layer.add(new Sprite(x, y, 0.9f, 0.9f, vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
            else
                layer.add(new Sprite(x, y, 0.9f, 0.9f, textures[rand() % 2]));
        }
    }

    GLint texIDs[] = {0, 1};
    shader.uniform("textures", texIDs, 2);

    float timer = 0.0f, start = glfwGetTime(), elapsed;
    unsigned int frames = 0;
    while (!window.closed()) {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);

        shader.enable();
        shader.uniform("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
        layer.render();

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