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
#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H
#include <string>
#include <vector>
#include <iostream>
#include "Resource.h"

namespace seneca{
    class Directory : public Resource{
        std::vector<Resource*> m_contents{};
    public:
        Directory(const std::string& dirName);
        void update_parent_path(const std::string& parentPath);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
        Directory& operator+=(Resource* newResource);
        Resource* find(const std::string& name, const std::vector<OpFlags>& flags = {});
        ~Directory();                  
        Directory(const Directory&) = delete;
        Directory& operator=(const Directory&) = delete;
        Directory(Directory&&) = delete;
        Directory& operator=(Directory&&) = delete;
        void remove(const std::string& name, const std::vector<OpFlags>& flags = {});
        void display(std::ostream& ostr, const std::vector<FormatFlags>& fflags = {}) const;
    };
}

#endif
