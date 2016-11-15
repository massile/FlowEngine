
#include "flow.h"

namespace FlowEngine {

    Flow::Flow()
    {

    }

    Flow::~Flow()
    {

    }

    Graphics::Window *Flow::createWindow(const char *name, int width, int height)
    {
        mWindow = new Graphics::Window(name, width, height);
        return mWindow;
    }

    void Flow::start()
    {
        init();
        run();
    }

    void Flow::run()
    {
        float updateTimer = 0.0f;
        const float updateTick = 1.0f / 60.0f;
        unsigned int frames = 0;
        unsigned int updates = 0;

        float timer = 0.0f, start = glfwGetTime(), elapsed = 0.0f;
        while (!mWindow->closed())
        {
            mWindow->clear();
            if (elapsed - updateTimer > updateTick) {
                update();
                updates++;
                updateTimer += updateTick;
            }
            render();
            frames++;
            mWindow->update();
            if (elapsed - timer > 1.0f) {
                tick();
                timer += 1.0f;
                mFramesPerSecond = frames;
                mUpdatesPerSecond = updates;
                frames = 0;
                updates = 0;
            }
            elapsed = glfwGetTime() - start;
        }
    }

}
