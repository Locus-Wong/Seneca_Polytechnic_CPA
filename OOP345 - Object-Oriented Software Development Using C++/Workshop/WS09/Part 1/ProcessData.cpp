// Workshop 9 - Multi-Threading, Thread Class

#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include "ProcessData.h"

namespace seneca
{
	// The following function receives array (pointer) as the first argument, number of array 
	//   elements (size) as second argument, divisor as the third argument, and avg as fourth argument. 
	//   size and divisor are not necessarily same. When size and divisor hold same value, avg will 
	//   hold average of the array elements. When they are different, avg will hold a value called 
	// 	 as average-factor. For part 1, you will be using same value for size and double. Use of 
	//   different values for size and divisor will be useful for multi-threaded implementation in part-2.
	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++)
		{
			avg += arr[i];
		}
		avg /= divisor;
	}
	// The following function receives array (pointer) as the first argument, number of array elements  
	//   (size) as second argument, divisor as the third argument, computed average value of the data items
	//   as fourth argument, and var as fifth argument. Size and divisor are not necessarily same as in the 
	//   case of computeAvgFactor. When size and divisor hold same value, var will get total variance of 
	//   the array elements. When they are different, var will hold a value called as variance factor. 
	//   For part 1, you will be using same value for size and double. Use of different values for size 
	//   and divisor will be useful for multi-threaded implementation in part-2.
	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++)
		{
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}

	ProcessData::operator bool() const {
		return total_items > 0 && data != nullptr;
	}

	// The following constructor of the functor receives name of the data file, opens it in
	//   binary mode for reading, reads first int data as total_items, allocate memory space
	//   to hold the data items, and reads the data items into the allocated memory space.
	//   It prints first five data items and the last three data items as data samples.
	ProcessData::ProcessData(const std::string& filename) {
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.
		std::ifstream file(filename, std::ios::binary);
		if (!file)
		{
			std::cerr << "Failed to open file: " << filename << std::endl;
			total_items = 0;
			data = nullptr;
			file.close();
		}
		else
		{
			file.read(reinterpret_cast<char*>(&total_items), sizeof(total_items));
			data = new int[total_items];
			file.read(reinterpret_cast<char*>(data), total_items * sizeof(int));
			std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
			std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
				<< data[total_items - 3] << ", " << data[total_items - 2] << ", "
				<< data[total_items - 1] << "]\n";
		}
	}

	ProcessData::~ProcessData()
	{
		delete[] data;
	}

	int ProcessData::operator()(const std::string& filename, double& avg, double& var)
	{
		computeAvgFactor(data, total_items, total_items, avg);
		computeVarFactor(data, total_items, total_items, avg, var);

		std::ofstream outFile(filename, std::ios::binary);
		if (!outFile)
		{
			std::cerr << "Failed to open output file: " << filename << std::endl;
			return -1;
		}
		else
		{
			outFile.write(reinterpret_cast<const char*>(&total_items), sizeof(total_items)); // reinterpret_cast allows the write function to treat the address as pointing to a sequence of bytes rather than a specific type.
			outFile.write(reinterpret_cast<const char*>(data), total_items * sizeof(int)); // reinterpret_cast allows the write function to treat the address as pointing to a sequence of bytes rather than a specific type.
			outFile.close();
		}
		return 0;
	}




}
