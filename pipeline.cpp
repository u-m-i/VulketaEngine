#include "pipeline.hpp"

#include<fstream>
#include<iostream>
#include<stdexcept>


using namespace std;

namespace Vulketa
{
	Pipeline::Pipeline(const string& vertFile, const string& fragFile)
	{
		createGraphicsPipeline(vertFile, fragFile);
	}

	vector<char> Pipeline::readFile(const string& filePath)
	{
		// create the file with bit flags for binary files
		ifstream file{ filePath, ios::ate | ios::binary };


		if (!file.is_open())
			throw runtime_error("failed to open file " + filePath);


		size_t fileSize = static_cast<size_t>(file.tellg());
		
		vector<char> buffer(fileSize);

		// Start reading from the start
		file.seekg(0);

		// Transfer all to the buffer

		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}

	void Pipeline::createGraphicsPipeline(const string& vertFile, const string& fragFile)
	{
		vector<char> vertCode = readFile(vertFile);

		vector<char> fragCode = readFile(fragFile);

		cout << "Vertex Shader SPIR-V length " << vertCode.size() << endl;
		cout << "Fragment Shaser SPIR-V length " << fragCode.size() << endl;
	}
}