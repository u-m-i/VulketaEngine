#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Vulketa
{
    class VulketaWindow
    {
    private:

        void createWindow();

        const int width, heigth;

        const char* name;

        GLFWwindow* window;

    public:

        VulketaWindow(const char* name, int w, int h);

        ~VulketaWindow();

        VulketaWindow(const VulketaWindow &) = delete;
        VulketaWindow& operator=(const VulketaWindow&) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window); }

        void createSurface(VkInstance instance, VkSurfaceKHR* surface);

    };
}