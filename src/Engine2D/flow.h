#pragma once

#include "graphics/sprite.h"
#include "graphics/renderer2d.h"
#include "graphics/batchRenderer2d.h"
#include "graphics/window.h"
#include "graphics/layers/layer.h"

namespace FlowEngine {

    class Flow
    {
    private:
        Graphics::Window* mWindow;
        unsigned int mFramesPerSecond, mUpdatesPerSecond;
    protected:
        Flow();
        virtual ~Flow();

        Graphics::Window* createWindow(const char *name, int width, int height);
    public:
        void start();

    protected:
        virtual void init() = 0;
        virtual void tick() {}
        virtual void update() {}
        virtual void render() = 0;

        const unsigned int getFPS() const { return mFramesPerSecond; }
        const unsigned int getUPS() const { return mUpdatesPerSecond; }

    private:
        void run();
    };

}