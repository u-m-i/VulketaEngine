#include "pipeline.hpp"

#include<fstream>


using namespace std;

namespace Vulketa
{
	vector<char> Pipeline::readFile(const string& filePath)
	{
		ifstream file{ filePath, ios::ate | ios::binary };


		if (!file.is_open())
			throw runtime_error("failed to open file " + filePath);

		size_t fileSize = static_cast<size_t>(file.tellg());

		vector<char> buffer(fileSize);

		file.seekg(0);

	}
}