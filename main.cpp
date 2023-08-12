
#include "application.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace Vulketa;

int main()
{
	Application app{};

	try
	{
		app.run();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}