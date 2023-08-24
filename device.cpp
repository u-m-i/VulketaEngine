#include "device.hpp"

#include <cstring>
#include <iostream>
#include <set>
#include <unordered_set>


namespace Vulketa
{
	void Device::setUpDebugger()
	{

	}



	/// Create Vulkan instance fullfilling it with the application information
	/// @remarks 
	void Device::create_instance()
	{
		if(enable_validation_layers && !checkValidationLayerSupport())
			throw std::runtime_error("Validation is required, but not available");


		// Instance's information

		VkApplicationInfo app_info = {};

		app_info.sType = Vk_STRUCTURE_TYPE_APPLICATIO_INFO;
		app_info.pApplicationName = "VulketaRenderer";
		app_info.applicationVersion = VK_MAKE_VERSION(1,0,0);
		app_info.pEngineName = "No Engine";
		app_info.engineVersion = VK_MAKE_VERSION(0,0,1);
		app_info.apiVersion = VK_API_VERSION_1_0;


		VkInstanceCreateInfo info_creation = {};

		info_creation.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		info_creation.pApplicationInfo = &app_info;

		auto extensions = getRequiredExtensions();

		// Get the total number of extensions
		info_creation.enabledExtensionCount = static_cast<uint32_t>(extendions.size());
		info_creation.ppEnabledExtensionNames = extensions.data();

		VkDebugUtilsMessengerCreateInfoEXT debug_info_creation;

		if(enableValidationLayer)
		{
			info_creation.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			info_creation.ppEnabledLayersNames = validationLayers.data();
		}
		else
		{
			info_creation.enabledLayerCount = 0;
			info_creation.pNext = nullptr;
		}

		if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCESS)
		{
			throw std::runtime_error("Failed to create the Vulkan Instance");
		}

		hasGlfwRequiredInstanceExtensions();

	}

}

