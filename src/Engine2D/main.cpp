#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/buffer/indexBuffer.h"
#include "graphics/buffer/vertexArray.h"
#include <glm/gtc/matrix_transform.hpp>

int main()
{
    using namespace FlowEngine;
    using namespace Graphics;
    using namespace glm;

    Window window("OpenGL", 960, 540);

    GLfloat vertices[] = {
        0, 0, 0,
        0, 3, 0,
        8, 3, 0,
        8, 0, 0
    };

    GLushort indices[] =  {
        0, 1, 2,
        2, 3, 0
    };

    GLfloat colorsA[] = {
        1, 0, 1, 1,
        1, 0, 1, 1,
        1, 0, 1, 1,
        1, 0, 1, 1
    };

    GLfloat colorsB[] = {
        0.2f, 0.3f, 0.8f, 1,
        0.2f, 0.3f, 0.8f, 1,
        0.2f, 0.3f, 0.8f, 1,
        0.2f, 0.3f, 0.8f, 1
    };

    VertexArray sprite1, sprite2;
    IndexBuffer ibo(indices, 6);

    sprite1.addBuffer(new VertexBuffer(vertices, 4 * 3, 3), 0);
    sprite1.addBuffer(new VertexBuffer(colorsA, 4 * 4, 4), 1);

    sprite2.addBuffer(new VertexBuffer(vertices, 4 * 3, 3), 0);
    sprite2.addBuffer(new VertexBuffer(colorsB, 4 * 4, 4), 1);


    Shader shader("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");
    shader.enable();
    shader.uniform("pr_matrix", ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));
    shader.uniform("ml_matrix", translate(mat4(), vec3(4, 3, 0)));

    shader.uniform("light_pos", vec2(4.0f, 1.5f));
    shader.uniform("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

    while (!window.closed())
    {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);
        shader.uniform("light_pos", vec2((float)(x * 16.0f / window.getWidth()), (float)(9.0f - y * 9.0f / window.getHeight())));

        sprite1.bind();
        ibo.bind();
            shader.uniform("ml_matrix", translate(mat4(), vec3(4, 3, 0)));
            glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
        ibo.unbind();
        sprite1.unbind();

        sprite2.bind();
        ibo.bind();
            shader.uniform("ml_matrix", translate(mat4(), vec3(0, 0, 0)));
            glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
        ibo.unbind();
        sprite2.unbind();

        window.update();
    }

    return 0;
}