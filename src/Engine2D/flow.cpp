#include "flow.h"

namespace FlowEngine {

    Flow::Flow() : m_FramesPerSecond(0), m_UpdatesPerSecond(0)
    {

    }

    Flow::~Flow()
    {
        delete m_Window;
    }

    Graphics::Window *Flow::createWindow(const char *name, int width, int height)
    {
        m_Window = new Graphics::Window(name, width, height);
        return m_Window;
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
        while (!m_Window->closed())
        {
            m_Window->clear();
            if (elapsed - updateTimer > updateTick) {
                update();
                updates++;
                updateTimer += updateTick;
            }
            render();
            frames++;
            m_Window->update();
            if (elapsed - timer > 1.0f) {
                tick();
                timer += 1.0f;
                m_FramesPerSecond = frames;
                m_UpdatesPerSecond = updates;
                frames = 0;
                updates = 0;
            }
            elapsed = glfwGetTime() - start;
        }
    }
}