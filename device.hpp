#pragma once

#include "vulketa_window.hpp"

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


	struct queueFamiliyIndices
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

		const bool enableValidationLayers = true;
#endif


		Device(const Device &) = delete;

		void operator=(const Device &) = delete;

		Device(Device &&) = delete;

		Device &operator=(Device &&) = delete;


		// Getters

		VkCommandPool getCommandPool()
		{
			return commandPool;
		}

		VkDevice getDevice()
		{
			return device;
		}

		VkSurfaceKHR getSurface()
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

		// Get queues family
		
		SwapChainSupportDetails get_swap_chain_support()
		{
			return query_swap_chain_support(physical_device);
		}

		QueueFamilyIndices find_physical_queue_family()
		{
			return find_queue_families(physical_device);
		}


		VkFormat find_supported_format( const vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

		void create_buffer( VkDevices size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer &buffer, VkDeviceMemory &buffer_memory);

		void copy_buffer(VkBuffer src_buffer, VkBuffer tartget_buffer, VkDeviceSize size);

		void copy_buffer(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layer_count);

		void create_info_and_image( const VkImageCreateInfo &image_info, VkMemoryPropertyFlags properties, VkDeviceMemory &image_memory);

		VkPhysicalDeviceProperties properties;


	private:
		
		///  Properties for the Device

		VkInstance instance;
		VkPhysicalDevice realDevice = VK_NULL_HANDLE;

		VkDebugUtilsMessengerEXT debugger;
		VulketaWindow& window;
		VkCommandPool commandPool;

		VkDevice device;
		VkSurfaceKHR surface;

		VkQueue graphics;
		VkQueue current;

		const vector<const char*> validationLayer = { "VK_LAYER_KHRONOS_validation" };
		const vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };


		// Configuration

		void setUpDebugger();
		void createInstance();
		void createSurface();

		void createCommandPool();
		void createLogicalDevice();

	};
}
