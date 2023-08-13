#pragma once
#include <string>
#include <vector>

using namespace std;

namespace Vulketa
{
	class Pipeline
	{
	public:
		Pipeline(const string& vertFile, const string& fragFile);

	private:
		static vector<char> readFile(const string& filePath);

		void createGraphicsPipeline(const string& vertFile, const string& fragFile);

	};
}