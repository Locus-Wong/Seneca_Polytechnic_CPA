/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 20 Jul 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#ifndef SENECA_DATABASE_H
#define SENECA_DATABASE_H
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Database.h"
namespace seneca
{
	enum class Err_Status
	{
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	template<typename T>
	class Database
	{
		static std::shared_ptr<Database> instance; // private class variable (static attribute) that will store the address of the one and only instance of type Database
		int numOfEntries{};
		std::string keys[20]; // statically-allocated array of strings with a size of 20
		T values[20]{}; // statically-allocated array of strings with a size of 20
		std::string filename{};

		Database(const std::string& filename); // private constructor to prevent client from instantiating this class.
		void encryptDecrypt(T& value) {};

	public:
		static std::shared_ptr<Database> getInstance(const std::string& filename);
		
		Err_Status GetValue(const std::string& key, T& value);
		Err_Status SetValue(const std::string& key, const T& value);
		~Database();
	};

	template<typename T>
	std::shared_ptr<Database<T>> Database<T>::instance = nullptr;


	template<>
	void Database<std::string>::encryptDecrypt(std::string& value)
	{
		const char secret[]{ "secret encryption key" };
		for (auto& C : value) // foreach character C in the parameter
		{
			for (const auto& K : secret) // foreach character K in the secret
			{
				C = C ^ K;
			}
		}
	}

	template<>
	void Database<long long>::encryptDecrypt(long long& value)
	{
		const char secret[]{ "super secret encryption key" };

		char* bytePtr = reinterpret_cast<char*>(&value); // get the address of the first byte of the parameter
		for (size_t i = 0; i < sizeof(long long); ++i) // foreach byte B in the parameter
		{
			for (const auto& K : secret) // foreach character K in the secret
			{
				bytePtr[i] = bytePtr[i] ^ K;
			}
		}

	}

	template<>
	Database<std::string>::Database(const std::string& filename) : numOfEntries(0), filename(filename)
	{
		std::cout << "[" << (void*)this << "] " << "Database(const std::string&)" << std::endl;

		std::ifstream inputFile(filename); // Open the file and read key-value pairs
		if (inputFile.is_open())
		{
			std::string line;
			while (std::getline(inputFile, line) && numOfEntries < 20)
			{
				size_t delimiterPos = line.find_first_of(" ");
				if (delimiterPos != std::string::npos)
				{
					std::string key = line.substr(0, delimiterPos);
					delimiterPos = line.find_first_not_of(" ", delimiterPos);
					std::string value = line.substr(delimiterPos);
					std::replace(key.begin(), key.end(), '_', ' '); // replaces any underscore character (_) that appears in the keys with a single space ( )
					keys[numOfEntries] = key;
					values[numOfEntries] = value;
					encryptDecrypt(values[numOfEntries]);
					++numOfEntries;
				}
			}
			inputFile.close();
		}
	}


	template<>
	Database<long long>::Database(const std::string& filename) : numOfEntries(0), filename(filename)
	{
		std::cout << "[" << (void*)this << "] " << "Database(const std::string&)" << std::endl;

		std::ifstream inputFile(filename); // Open the file and read key-value pairs
		if (inputFile.is_open())
		{
			std::string line;
			while (std::getline(inputFile, line) && numOfEntries < 20)
			{
				size_t delimiterPos = line.find_first_of(" ");
				if (delimiterPos != std::string::npos)
				{
					std::string key = line.substr(0, delimiterPos);
					delimiterPos = line.find_first_not_of(" ", delimiterPos);
					std::string stringValue = line.substr(delimiterPos);
					long long value = std::stoll(stringValue); // convert the string to a long long
					std::replace(key.begin(), key.end(), '_', ' '); // replaces any underscore character (_) that appears in the keys with a single space ( )
					keys[numOfEntries] = key;
					values[numOfEntries] = value;
					encryptDecrypt(values[numOfEntries]);
					++numOfEntries;
				}
			}
			inputFile.close();
		}
	}

	template<typename T>
	 std::shared_ptr<Database<T>> Database<T>::getInstance(const std::string& filename)
	{
		if (instance == nullptr) // if the instance has not been created yet
		{
			instance = std::shared_ptr<Database<T>>(new Database<T>(filename)); // create a new instance of Database and store it in the static attribute
		}
		return instance;
	}

	template<typename T>
	Err_Status Database<T>::GetValue(const std::string& key, T& value)
	{
		for (int i = 0; i < numOfEntries; ++i)
		{
			if (keys[i] == key) // if the key is found
			{
				value = values[i]; // store the corresponding value 
				return Err_Status::Err_Success;
			}
		}
		return Err_Status::Err_NotFound;
	}

	template<typename T>
	Err_Status Database<T>::SetValue(const std::string& key, const T& value)
	{
		if (numOfEntries < 20) // if there is space in the database
		{
			keys[numOfEntries] = key;
			values[numOfEntries] = value;
			++numOfEntries;
			return Err_Status::Err_Success;
		}
		return Err_Status::Err_OutOfMemory;

	}

	template<typename T>
	Database<T>::~Database()
	{
		std::cout << "[" << this << "] " << "~Database()" << std::endl;
		std::ofstream backupFile(filename + ".bkp.txt"); // Create a backup file (input file name with the string .bkp.txt)
		for (int i = 0; i < numOfEntries; ++i)
		{
			encryptDecrypt(values[i]);
			backupFile << std::left << std::setw(25) << keys[i] << " -> " << values[i] << std::endl; // size 25 characters, aligned to the left
		}
		backupFile.close();
	}
}
#endif