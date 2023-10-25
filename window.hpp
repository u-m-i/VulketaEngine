#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Vulketa
{
    class Window
    {
    private:

        void createWindow();

        const int width, heigth;

        const char* name;

        GLFWwindow* window;

        VkResult result;

    public:

        Window(const char* name, int w, int h);

        ~Window();

        Window(const Window &) = delete;
        Window& operator=(const Window&) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }

        void create_window_surface(VkInstance instance, VkSurfaceKHR* surface);

    };
}