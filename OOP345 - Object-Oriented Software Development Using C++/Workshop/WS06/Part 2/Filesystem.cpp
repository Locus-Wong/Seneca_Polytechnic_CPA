/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 09 July 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#include <fstream>
#include <string>
#include <exception>
#include "File.h"
#include "Directory.h"
#include "Filesystem.h"
namespace seneca
{
	Filesystem::Filesystem(const std::string& fileName, const std::string& rootDirName) : m_root(new Directory(rootDirName)), m_current(m_root)
	{
		auto removeSpace = [](std::string& name) -> std::string&
			{
				size_t start = name.find_first_not_of(' '); // Find the first non-space character
				size_t end = name.find_last_not_of(' '); // Find the last non-space character

				if (start != std::string::npos && end != std::string::npos)
				{
					name = name.substr(start, end - start + 1); // Extract the substring without leading and trailing spaces
				}
				else
				{
					name.clear(); // The string is all spaces
				}

				return name;
			};

		std::ifstream file(fileName);
		if (!file)
		{
			delete m_root; // Clean up the root directory if the file cannot be opened
			throw std::string("Cannot open file: ") + fileName;
		}
		std::string line;
		while (std::getline(file, line))
		{
			std::string path, contents;
			size_t separatedPos = line.find('|');
			if (separatedPos != std::string::npos) // File
			{
				path = line.substr(0, separatedPos); 
				contents = line.substr(separatedPos + 1);
			}
			else
			{
				path = line;  // Directory
			}
			path = removeSpace(path);
			contents = removeSpace(contents);
			add_resource(path, contents);
		}
	}

	Filesystem& Filesystem::operator+=(Resource* newResource)
	{
		  *m_current += std::move(newResource); // Add the resource to the current directory
		return *this;
	}

	Directory* Filesystem::change_directory(const std::string& dirName)
	{
		if (dirName.empty()) 
		{
			m_current = m_root; // go to the root directory
			return m_current;
		}
		Resource* found = m_current->find(dirName); // find if the directory is in the current directory
		if (!found)
		{
			throw std::invalid_argument("Cannot change directory! " + dirName + " not found!");
		}
		m_current = dynamic_cast<Directory*>(found);
		return m_current;
	}

	Directory* Filesystem::get_current_directory() const
	{
		return m_current;
	}

	Filesystem::~Filesystem()
	{
		delete m_root; 
	}

	void Filesystem::add_resource(const std::string& path, const std::string& contents)
	{
		std::vector<std::string> tokens;
		size_t start = 0, end = 0;
		while ((end = path.find('/', start)) != std::string::npos)
		{
			if (end != start)
			{
				tokens.push_back(path.substr(start, end - start + 1)); // e.g. "images/", "pngs/", "videos/"
			}
			start = end + 1;
		}
		if (start < path.size())
		{
			tokens.push_back(path.substr(start)); // e.g. "cat.jpg", "dog.jpg", ".flamingo.gif"
		}

		Directory* currentDir = m_root;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			Resource* res = currentDir->find(tokens[i]); // find if the token is already in the current directory

			if (i == tokens.size() - 1) // Last token
			{
				if (tokens[i].find('.') != std::string::npos) // File
				{
					if (!res) // if the file is not found in the current directory
					{
						File* file = new File(tokens[i], contents);
						*currentDir += file;
					}
				}
				else // Directory
				{
					if (!res) // if the directory is not found in the current directory
					{
						Directory* dir = new Directory(tokens[i]);
						*currentDir += dir; 
					}
				}
			}
			else
			{
				if (!res) // Intermediate directories
				{
					Directory* dir = new Directory(tokens[i]);
					*currentDir += dir;
					currentDir = dir; // Move to the next directory
				}
				else
				{
					currentDir = dynamic_cast<Directory*>(res); // Move to the next directory
				}
			}
		}

	}
}