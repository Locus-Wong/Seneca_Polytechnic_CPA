#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Database.h"
#include "Database.h" // intentional

int cout = 0; // won't compile if headers don't follow convention

int main(int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; ++i)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc != 2)
	{
		std::cout << "Usage: w8 data.txt\n";
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

		auto db1 = seneca::Database::getInstance(argv[1]);
		auto db2 = seneca::Database::getInstance("nothing");

		if (db1 == db2)
			std::cout << "Same database.\n\n";
		else
			std::cout << "Different database.\n\n";
	}

	{
		// TEST #2: test content of database

		std::string keys[]{ "Naomi Osaka", "Ashleigh Barty", "Karolina Pliskova", "Barbora Krejcikova", "Leylah Fernandez" };
		std::sort(keys, keys + sizeof(keys) / sizeof(keys[0]));

		for (auto& key : keys)
		{
			auto dB = seneca::Database::getInstance(key); // the parameter should be ignored
			std::string value;
			if (dB->GetValue(key, value) == seneca::Err_Status::Err_Success)
				std::cout << key << " earned " << value << std::endl;
			else
				std::cout << "Unable to retrieve earnings for " << key << std::endl;
		}
	}

	return cout;
}
