#include "device.hpp"

#include <cstring>
#include <iostream>
#include <set>
#include <unordered_set>


namespace Vulketa
{
	void Device::set_up_debugger()
	{

	}

	/// Create Vulkan instance fullfilling it with the application information
	/// @remarks 
	void Device::create_instance()
	{
		if(enable_validation_layers && !check_validation_layer_support())
			throw std::runtime_error("Validation is required, but not available");


		// Instance's information

		VkApplicationInfo app_info = {};

		app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		app_info.pApplicationName = "VulketaRenderer";
		app_info.applicationVersion = VK_MAKE_VERSION(1,0,0);
		app_info.pEngineName = "VulketaEngine";
		app_info.engineVersion = VK_MAKE_VERSION(0,0,1);
		app_info.apiVersion = VK_API_VERSION_1_0;


		VkInstanceCreateInfo info_creation = {};

		info_creation.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		info_creation.pApplicationInfo = &app_info;

		auto extensions = get_required_extensions();

		// Get the total number of extensions
		info_creation.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		info_creation.ppEnabledExtensionNames = extensions.data();

		VkDebugUtilsMessengerCreateInfoEXT debug_info_creation;

		if(enable_validation_layers)
		{
			info_creation.enabledLayerCount = static_cast<uint32_t>(validation_layers.size());
			info_creation.ppEnabledLayerNames = validation_layers.data();
		}
		else
		{
			info_creation.enabledLayerCount = 0;
			info_creation.pNext = nullptr;
		}

		if(vkCreateInstance(&info_creation, nullptr, &instance) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create the Vulkan Instance");
		}

		
		// Confirm glfw instance extensions
		has_glfw_required_instance_extensions();
	}
}
