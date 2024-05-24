//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 07 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
 // OOP244 Workshop # 6
 //
 // File:    EmailFile.h
 // Version 1.0
 // Date:
 // Author: Sina Talebi Moghaddam
 // Description
 // This file must be completed by students
 // Revision History
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 /////////////////////////////////////////////////////////////////
 ***********************************************************************/
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca{

const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record

class EmailFile;
class Email
{
    char* m_email{ nullptr }; // holds the address of the dynamically allocated Cstring (to hold the email address)
    char* m_name{ nullptr }; // holds the address of the dynamically allocated Cstring (to hold the name associated with the email)
    char m_year[5]{'\0'}; // A Cstring to store the year information.
    Email() {};
    Email& operator=(const Email&);
    bool load(std::ifstream& in);
    ~Email();
    // Prohibit the copy constructor for this class:
    Email(const Email& src) = delete;
    // Make the EmailFile class a "friend" of the Email class
    friend class EmailFile;
};


class EmailFile
{
    Email* m_emailLines{ nullptr }; // A pointer to hold an array of Email objects.
    char* m_filename{}; // A pointer intended to hold the name of the file associated with an EmailFile object.
    int m_noOfEmails{ 0 }; // An integer to be set to the number of emails in the file.
    void setFilename(const char* filename);
    void setEmpty();
    bool setNoOfEmails();
    void loadEmails();
    void copy(const EmailFile& src); // private function that performs the copying process
    
public:
    std::ostream& view(std::ostream& ostr) const;
    operator bool() const;
    EmailFile();
    ~EmailFile();
    EmailFile(const char* filename);
    EmailFile(const EmailFile& src); // Copy constructor
    EmailFile& operator=(const EmailFile& src); // Copy assignment operator
    bool saveToFile(const char* filename) const;
    void fileCat(const EmailFile& obj, const char* name = nullptr);
};

std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);

}
#endif // !SENECA_EMAILFILE_H
