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
#include "Resource.h"
#include "Flags.h"
#include "File.h"

namespace seneca{

File::File(const std::string& name, const std::string& contents):m_contents(contents){
    m_name = name;
}

void File::update_parent_path(const std::string& parentPath){ // sets the parent path to the parameter.
    m_parent_path = parentPath;
}

NodeType File::type() const{
    return NodeType::FILE;
}

std::string File::path() const{
    return m_parent_path + m_name; // returns the full absolute path of the file
}

std::string File::name() const{
    return m_name;
}

int File::count() const{
    return -1;
}

size_t File::size() const{
    return m_contents.size(); // returns the size of the file in bytes. For simplicity, this is the number of characters in m_contents attribute
}

File::~File()
{

}

}
