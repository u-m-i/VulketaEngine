#include "vulketa_window.hpp"

#include <iostream>

using namespace std;

namespace Vulketa
{
    VulketaWindow::VulketaWindow(const char* name, int w, int h) : name{ name }, width{ w }, heigth{ h }
    {
        createWindow();
    }

    VulketaWindow::~VulketaWindow()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void VulketaWindow::createWindow()
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
}