#pragma once

#include "window.hpp"
#include "pipeline.hpp"

namespace Vulketa
{
    class Application
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGTH = 600;
        const char* name = "vulketa";

        void run();

    private:
        Window real_window{ name, WIDTH, HEIGTH };
        Pipeline pipeline{ "./shaders/triangle.vert.spv", "./shaders/triangle.frag.spv" };
    };
}