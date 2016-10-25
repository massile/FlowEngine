#include "ui/Window.h"

int main()
{
    Window window("OpenGL", 800, 800);

    float lastTime = 0;
    while(!window.shouldClose()) {
        window.clear();
        if(lastTime) {
            window.update(glfwGetTime() - lastTime);
        }
        lastTime = glfwGetTime();
    }

 	return 0;
}