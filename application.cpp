#include "application.hpp"

namespace Vulketa
{
	void Application::run()
	{
		while (!real_window.shouldClose())
		{
			// Check and process the window events
			glfwPollEvents();

		}
	}
}