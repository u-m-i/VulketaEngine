#pragma once

#include "vulketa_window.hpp"

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
        VulketaWindow real_window{ name, WIDTH, HEIGTH };
    };
}