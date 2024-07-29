#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Database.h"
#include "Database.h" // intentional

int cout = 0; // won't compile if headers don't follow convention

void dumpFileAsHex(const char* filename);

int main(int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; ++i)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc != 3)
	{
		std::cout << "Usage: w8 <file_str.txt> <file_num.txt>\n";
		return -1;
	}

	{
		// TEST #1: Singleton

		// getInstance() creates an object of type Database
		//   if that object does not already exist.
		// If that object already exists, getInstance will
		//   return that object.
		// The parameter is useful only in the first call,
		//   after that it should have no impact.

		void* db1 = seneca::Database<std::string>::getInstance(argv[1]).get();
		void* db2 = seneca::Database<long long>::getInstance(argv[2]).get();
		void* db3 = seneca::Database<std::string>::getInstance("nothing").get();
		void* db4 = seneca::Database<long long>::getInstance("nothing").get();

		std::cout << (db1 == db3 ? "Same" : "Different") << " database.\n";   // Same
		std::cout << (db2 == db4 ? "Same" : "Different") << " database.\n";   // Same
		std::cout << (db1 == db2 ? "Same" : "Different") << " database.\n";   // Different
		std::cout << (db1 == db4 ? "Same" : "Different") << " database.\n";   // Different
	}

	std::cout << "\n******************************\n";

	{
		// TEST #2: test content of a string database

		std::string keys[]{ "Naomi Osaka", "Ashleigh Barty", "Karolina Pliskova", "Barbora Krejcikova", "Leylah Fernandez" };
		std::sort(keys, keys + sizeof(keys) / sizeof(keys[0]));

		for (auto& key : keys)
		{
			auto dB = seneca::Database<std::string>::getInstance(key); // the parameter should be ignored
			std::string value;
			if (dB->GetValue(key, value) == seneca::Err_Status::Err_Success)
				std::cout << key << " earned " << value << std::endl;
			else
				std::cout << "Unable to retrieve earnings for " << key << std::endl;
		}

		// Change the database's content
		auto dB = seneca::Database<std::string>::getInstance("");
		if (dB->SetValue("Leylah Fernandez", "$786,772") == seneca::Err_Status::Err_Success)
		{
			std::string value;
			if (dB->GetValue("Leylah Fernandez", value) == seneca::Err_Status::Err_Success)
				std::cout << "Leylah Fernandez earned " << value << std::endl;
			else
				std::cout << "Unable to retrieve earnings for Leylah Fernandez.\n";
		}
	}

	std::cout << "\n******************************\n";

	{
		// TEST #3: test content of a numeric database

		std::string keys[]{ "Naomi Osaka", "Ashleigh Barty", "Karolina Pliskova", "Barbora Krejcikova", "Leylah Fernandez" };
		std::sort(keys, keys + sizeof(keys) / sizeof(keys[0]));

		for (auto& key : keys)
		{
			auto dB = seneca::Database<long long>::getInstance(key); // the parameter should be ignored
			long long value;
			if (dB->GetValue(key, value) == seneca::Err_Status::Err_Success)
				std::cout << key << " earned " << value << std::endl;
			else
				std::cout << "Unable to retrieve earnings for " << key << std::endl;
		}

		// Change the database's content
		auto dB = seneca::Database<long long>::getInstance("");
		dB->SetValue("Leylah Fernandez", 786772);
		long long value;
		if (dB->GetValue("Leylah Fernandez", value) == seneca::Err_Status::Err_Success)
			std::cout << "Leylah Fernandez earned " << value << std::endl;
		else
			std::cout << "Unable to retrieve earnings for Leylah Fernandez.\n";
	}

	std::cout << "\n******************************\n";

	dumpFileAsHex("data_str.txt.bkp.txt");
	dumpFileAsHex("data_num.txt.bkp.txt");

	return cout;
}

void dumpFileAsHex(const char* filename)
{
	std::fstream file(filename, std::ios::in | std::ios::ate | std::ios::binary);
	char c{};
	int cnt{ 1 };
	std::cout << "\nThe content of the file [" << filename << "]\n";
	std::cout << "---------------------------------------------------------------------\n";
	std::cout << "File size in bytes: [ " << file.tellg() << std::setfill('0') << std::hex;
	file.seekg(std::ios::beg);
	while (file.get(c))
	{
		if (cnt % 20 == 1)
			std::cout << " ]\n" << std::setw(4) << (1 + cnt / 20) << ": [";
		std::cout << " " << std::setw(2) << static_cast<unsigned short>(c);
		++cnt;
	}
	file.close();
	std::cout << " ]" << std::setfill(' ') << std::dec;
	std::cout << "\n---------------------------------------------------------------------\n";
}
