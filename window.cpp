#include "window.hpp"

#include <iostream>

using namespace std;

namespace Vulketa
{
    Window::Window(const char* name, int w, int h) : name{ name }, width{ w }, heigth{ h }
    {
        createWindow();
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::createWindow()
    {
        // Initialize the library of GLFW
        if (!glfwInit())
        {
            cerr << "Error Initializing GLFW";
        }

        // Call the glfw window hint, to do not open a OpenGL context
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        // Deny resize
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, heigth, name, nullptr, nullptr);

    }

    void Window::create_window_surface(VkInstance instance, VkSurfaceKHR* surface)
    {
        result = glfwCreateWindowSurface(instance, window, nullptr, surface);

        if (result != VK_SUCCESS)
            throw runtime_error("failed to create the windows surface, check the GLFW library and Vulkan library.");

    }
}