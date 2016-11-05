#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/renderable2d.h"
#include "graphics/sprite.h"
#include "graphics/batchRenderer2d.h"
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

    std::vector<Renderable2D*> sprites;
    for (float y = 0; y < 9.0f; y += 0.05) {
        for (float x = 0; x < 16.0f; x += 0.05) {
            sprites.push_back(new Sprite(x, y, 0.05f, 0.05f, glm::vec4(0.5, rand() % 1000 / 1000.0f, 1, 1)));
        }
    }

    BatchRenderer2D renderer;


    Shader shader("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");
    shader.enable();
    shader.uniform("pr_matrix", ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));
    shader.uniform("light_pos", vec2(4.0f, 1.5f));

    while (!window.closed())
    {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);
        shader.uniform("light_pos", vec2((float)(x * 16.0f / window.getWidth()), (float)(9.0f - y * 9.0f / window.getHeight())));

        renderer.begin();
        for (int i = 0; i < sprites.size(); i++)
            renderer.submit(sprites[i]);
        renderer.end();

        renderer.flush();
        window.update();
    }

    return 0;
}