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
#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H
#include <string>
#include "Directory.h"
namespace seneca
{
	class Filesystem
	{
		Directory* m_root{};
		Directory* m_current{};
	public:
		Filesystem(const std::string& fileName, const std::string& rootDirName = "");
		Filesystem& operator+=(Resource* newResource); // adds a resource to the current directory.
		Directory* change_directory(const std::string& dirName = "");
		Directory* get_current_directory() const;
		void add_resource(const std::string& path, const std::string& contents);
		~Filesystem();
		Filesystem(const Filesystem&) = delete;
		Filesystem& operator=(const Filesystem&) = delete;
		Filesystem(Filesystem&&) = default;
		Filesystem& operator=(Filesystem&&) = default;
	};
}
#endif

