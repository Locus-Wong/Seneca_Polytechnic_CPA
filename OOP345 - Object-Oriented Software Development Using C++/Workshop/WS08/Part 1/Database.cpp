#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>
#include <iomanip>
#include "Database.h"
namespace seneca
{

	std::shared_ptr<Database> Database::instance = nullptr;

    Database::Database(const std::string& filename) : filename(filename), numOfEntries(0)
    {
        std::cout << std::hex << "[" << (int*)this << "] " << "Database(const std::string&)" << std::endl;

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
                    delimiterPos = line.find_first_of("$", delimiterPos);
                    std::string value = line.substr(delimiterPos); // include the dollar sign
                    std::replace(key.begin(), key.end(), '_', ' '); // replaces any underscore character (_) that appears in the keys with a single space ( )
                    keys[numOfEntries] = key;
                    values[numOfEntries] = value;
                    ++numOfEntries;
                }
            }
            inputFile.close();
        }
    }

    std::shared_ptr<Database> Database::getInstance(const std::string& filename)
    {
        if (instance == nullptr) // if the instance has not been created yet
        {
			instance = std::shared_ptr<Database>(new Database(filename)); // create a new instance of Database and store it in the static attribute
		}
        return instance;
    }

    Err_Status Database::GetValue(const std::string& key, std::string& value)
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

    Err_Status Database::SetValue(const std::string& key, const std::string& value)
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

    Database::~Database()
	{
        std::cout << "[" << this << "] " << "~Database()" << std::endl;


        std::ofstream backupFile(filename + ".bkp.txt"); // Create a backup file (input file name with the string .bkp.txt)
        for (int i = 0; i < numOfEntries; ++i)
        {
            backupFile << std::left << std::setw(25) << keys[i] << "-> " << values[i] << std::endl; // size 25 characters, aligned to the left
        }
        backupFile.close();
	}

}