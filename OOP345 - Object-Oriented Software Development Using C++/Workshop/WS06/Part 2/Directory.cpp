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
#include <string>
#include <exception>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "Resource.h"
#include "Flags.h"
#include "Directory.h"

namespace seneca
{
    Directory::Directory(const std::string& dirName)
    {
        m_name = dirName;  
    }

    void Directory::update_parent_path(const std::string& parentPath)
    {
        if(parentPath != "/") // assume all directory names end with a "/"
		{
            m_parent_path = parentPath;
		}
        // For each resource that this directory holds, this member should also set their absolute path locations to the full absolute path of this directory.
        for (auto& el : m_contents)
        {
            el->update_parent_path(m_parent_path + m_name);
        }
    }

    NodeType Directory::type() const
    {
        return NodeType::DIR;
    }

    std::string Directory::path() const
    {
        return m_parent_path + m_name; // returns the full absolute path of the directory
    }

    std::string Directory::name() const
    {
        return m_name;
    }

    int Directory::count() const
    {
        return m_contents.size(); // returns the number of resources that this directory holds
    }

    size_t Directory::size() const
    {
        size_t totalSize = 0u;
        for (auto& el : m_contents)
        {
            totalSize += el->size();
        }
        return totalSize; // returns the size of the directory in bytes
    }

    Directory& Directory::operator+=(Resource* newResource)
    {
        for (auto& el : m_contents)
        {
            if (el->name() == newResource->name())
            { // if a match is found, throw an exception
                throw std::runtime_error("Resource already exists in the directory");
            }
        }
        // if no match is found, add the resource and update the absolute path location of the added resource with the directory's full absolute path
        m_contents.push_back(newResource);
        newResource->update_parent_path(this->path());
        return *this;
    }

    Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags)
    {
        for (auto& el : m_contents)
        {
            if (el->name() == name)
            { // if a match is found, return the address of resource
                return el;
            }
            if (el->type() == NodeType::DIR) // If an element in m_contents is a directory
            {
                for (auto& flag : flags)
                {
                    if (flag == OpFlags::RECURSIVE) // if the RECURSIVE flag is in the second parameter
                    { 
                        Resource* found = dynamic_cast<Directory*>(el)->find(name, flags); // cast Resource* to Directory* and call its find() member function
                        if (found)
                        {
                            return found;
                        }
                    }
                }
            }
        }
        return nullptr; // return nullptr if no match is found
    }

    Directory::~Directory()
    {
        for (Resource* res : m_contents)
        {
            delete res; // Delete each resource in the directory
        }
    }

    void Directory::remove(const std::string& name, const std::vector<OpFlags>& flags)
    {
            for (auto it = m_contents.begin(); it != m_contents.end(); ++it) // iterate through the m_contents vector
            {
                if ((*it)->name() == name) // if a match is found
                {
                    if ((*it)->type() == NodeType::DIR && std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) == flags.end()) // if the resource is a directory and the RECURSIVE flag is not in the second parameter
                    {
                        throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
                    }
                    delete* it; // delete the resource
                    m_contents.erase(it); // erase the resource from the vector
                    return;
                }
            }
            throw std::string(name + " does not exist in " + m_name);

        
        // If no matching resource is found, report an exception of type std::string with the message NAME does not exist in DIRECTORY_NAME.
        throw std::string(name + " does not exist in " + m_name);

    }

    void Directory::display(std::ostream& ostr, const std::vector<FormatFlags>& fflags) const
    {
        ostr << "Total size: " << size() << " bytes" << std::endl;
        for (auto& el : m_contents)
        {
            if (el->type() == NodeType::DIR)
            {
                // If the resource is a directory
                ostr << "D | " << std::left << std::setw(15) << el->name() << " |";
                for (auto& flag : fflags)
                {
                    if (flag == FormatFlags::LONG)
                    {
                        if (el->count())
                        {
                            ostr << std::right << std::setw(3)  << el->count() << " | " << std::right << std::setw(4) << el->size() << " bytes |";
                        }
                        else
                        {
                            ostr << std::right << std::setw(3) << el->count() << " | " << std::setw(4) << el->size() << " bytes |";
                        }
                    }
                }
                ostr << std::endl;
            }
            else
            {
                // If the resource is a file
                ostr << "F | " << std::left << std::setw(15) << el->name() << " |";
                for (auto& flag : fflags)
                {
                    if (flag == FormatFlags::LONG)
                    {
                            ostr << std::right << std::setw(5) << "|" << std::setw(5) << std::right << el->size() << " bytes |";
                    }
                }
                ostr << std::endl;
            }
        }

    }
}