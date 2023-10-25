#pragma once

#include "window.hpp" // INNER

#include<vector>

using namespace std;

namespace Vulketa
{
	struct swapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilites;
		vector<VkSurfaceFormatKHR> formats;
		vector<VkPresentModeKHR> presentModes;
	};


	struct queueFamilyIndices
	{
		uint32_t graphicsFamily;
		uint32_t presentFamily;

		bool graphicsFamilyHasValue = false;
		bool presentFamilyHasValue = false;

		bool isComplete()
		{
			return graphicsFamilyHasValue && presentFamilyHasValue;
		}
	};

	class Device
	{
	public:
#ifdef DEGUB

		const bool enableValidationLayer = false;
#else

		const bool enable_validation_layers = true;
#endif

		VkPhysicalDeviceProperties properties;


		// Operators

		Device(const Device &) = delete;

		void operator=(const Device &) = delete;

		Device(Device &&) = delete;

		Device &operator=(Device &&) = delete;


		// Getters

		VkCommandPool get_command_pool()
		{
			return command_pool;
		}

		VkDevice get_device()
		{
			return device;
		}

		VkSurfaceKHR get_surface()
		{
			return surface;
		}

		VkQueue get_graphics_queue()
		{
			return graphics_queue;
		}

		VkQueue get_present_queue()
		{
			return present_queue;
		}

		// Gettters for queues families
		
		swapChainSupportDetails get_swap_chain_support()
		{
			return query_swap_chain_support(physical_device);
		}

		queueFamilyIndices find_physical_queue_family()
		{
			return find_queue_families(physical_device);
		}

		uint32_t find_mem_type(uint32_t type_filder, VkMemoryPropertyFlags properties);


		VkFormat find_supported_format( const vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

		void create_buffer( VkDevice size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer &buffer, VkDeviceMemory &buffer_memory);

		void copy_buffer(VkBuffer src_buffer, VkBuffer tartget_buffer, VkDeviceSize size);

		void copy_buffer_to_image(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layer_count);

		void create_info_and_image( const VkImageCreateInfo &image_info, VkMemoryPropertyFlags properties, VkDeviceMemory &image_memory);



	private:
		
		///  Properties for the Device

		VkInstance instance;
		VkPhysicalDevice physical_device = VK_NULL_HANDLE;
		VkDebugUtilsMessageSeverityFlagsEXT severity_flags = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
																													VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT; 

		VkDebugUtilsMessageTypeFlagsEXT message_flags = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
																										VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | 
																										VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

		VkDebugUtilsMessengerEXT debugger;
		Window& window;
		VkCommandPool command_pool;

		VkDevice device;
		VkSurfaceKHR surface;

		VkQueue graphics_queue;
		VkQueue present_queue;

		const vector<const char*> validation_layers = { "VK_LAYER_KHRONOS_validation" };
		const vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

		// Queries for queues & swap chains

		swapChainSupportDetails query_swap_chain_support(VkPhysicalDevice device);

		queueFamilyIndices find_queue_families(VkPhysicalDevice device);

		bool check_validation_layer_support();

		bool check_device_extension_support(VkPhysicalDevice device);

		vector<const char*> get_required_extensions();


		// Configuration

		void set_up_debugger();
		void create_instance();
		void create_surface();

		void create_command_pool();
		void create_logical_device();

		void has_glfw_required_instance_extensions();

		void populate_debug_messenger(VkDebugUtilsMessengerCreateInfoEXT &creation_info);
	};
}
