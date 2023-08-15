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