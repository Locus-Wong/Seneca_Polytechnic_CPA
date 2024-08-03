/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 03 Aug 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#include "Utilities.h"
#include <string>
namespace seneca {

char Utilities::m_delimiter = '0';

void Utilities::setDelimiter(char newDelimiter)
{
    m_delimiter = newDelimiter;
}

char Utilities::getDelimiter()
{
    return m_delimiter;
}

// set the field width for the current object to the value of the parameter received
void Utilities::setFieldWidth(size_t newWidth)
{
    m_widthField = newWidth;
}

// return the field width for the current object
size_t Utilities::getFieldWidth() const
{
    return m_widthField;
}

// extract a token from the first parameter
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
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
    
    std::string token;
    size_t pos = str.find(m_delimiter, next_pos);
    if (pos != std::string::npos) // If the delimiter is found
    {
        if (pos == next_pos) // If the delimiter is found at next_pos
        {
            more = false;
            throw "Error";
        }
        token = str.substr(next_pos, pos - next_pos);
        token = removeSpace(token);
        next_pos = pos + 1;
        if (m_widthField < token.size()) // Updates the current object's m_widthField data member if its current value is less than the size of the token extracted
        {
            setFieldWidth(token.size());
        }
        more = true;
    }
    else // If the delimiter is not found
    {
        token = str.substr(next_pos);
        token = removeSpace(token);
        if (m_widthField < token.size()) // Updates the current object's m_widthField data member if its current value is less than the size of the token extracted
        {
            setFieldWidth(token.size());
        }
        more = false;
    }
    return token;
}
};
