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

			bool shouldClose() { return glfwWindowShouldClose(window); }
	};
}

