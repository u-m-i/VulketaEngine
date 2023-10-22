#include "device.hpp"

#include <cstring>
#include <iostream>
#include <set>
#include <unordered_set>


namespace Vulketa
{
	/// <summary>
	/// Configures the messenger for debugging severity and type and callback pointer
	/// </summary>
	/// <param name="create_info"></param>
	void Device::populate_debug_messenger(VkDebugUtilsMessengerCreateInfoEXT& create_info)
	{

		// Empty the instance 

		create_info = {};

		// Configuration
		create_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;

		create_info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	}

	void Device::set_up_debugger()
	{
		// If there is no validation layers, the debuger is not created
		if (!enable_validation_layers)
			return;

		// Messenger allocation

		VkDebugUtilsMessengerCreateInfoEXT creation_info;



		// ERROR => The creation for the debugger was not succcessful


	}

	/// Create Vulkan instance fullfilling it with the application information
	/// @remarks 
	void Device::create_instance()
	{
		if(enable_validation_layers && !check_validation_layer_support())
			throw std::runtime_error("Validation is required, but not available");



		VkApplicationInfo app_info = {};

		app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		app_info.pApplicationName = "VulketaRenderer";
		app_info.applicationVersion = VK_MAKE_VERSION(1,0,0);
		app_info.pEngineName = "VulketaEngine";
		app_info.engineVersion = VK_MAKE_VERSION(0,0,1);
		app_info.apiVersion = VK_API_VERSION_1_0;


		// Instance's information

		VkInstanceCreateInfo info_creation = {};

		// Set the type for the structure and get the reference for the application info
		info_creation.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		info_creation.pApplicationInfo = &app_info;

		std::vector<const char*> extensions = get_required_extensions();

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

		// ERROR => Vulketa Instance is not being able to create
		if(vkCreateInstance(&info_creation, nullptr, &instance) != VK_SUCCESS)
			throw std::runtime_error("Failed to create the Vulkan Instance");

		
		// Confirm glfw instance extensions
		has_glfw_required_instance_extensions();
	}
}
