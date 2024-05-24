//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 07 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
 // OOP244 Workshop # 6
 //
 // File: EmailFile.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{
Email& Email::operator=(const Email& rhs) { // This function is used to assign the values from one Email object to another.
    
    if (this != &rhs && rhs.m_email && rhs.m_name) {
        delete[] m_email;
        m_email = nullptr;
        m_email = new char[strlen(rhs.m_email) + 1];
        strcpy(m_email, rhs.m_email);
        delete[] m_name;
        m_name = nullptr;
        m_name = new char[strlen(rhs.m_name) + 1];
        strcpy(m_name, rhs.m_name);
        strcpy(m_year, rhs.m_year);
    }
    
    return *this;
}

bool Email::load(std::ifstream& in) { // This function reads data from an input file stream and populates the Email object's members with this data. It reads the email address, name, and year from the file and stores them in the object's members. It returns a boolean value indicating the success or failure of the loading process.
    
    char buffer[BUFFER_SIZE];
    bool result = false;
    
    if (in.getline(buffer, BUFFER_SIZE, ',')) {
        delete[] m_email;
        m_email = new char[strlen(buffer) + 1];
        strcpy(m_email, buffer);
        
        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_name;
            m_name = new char[strlen(buffer) + 1];
            strcpy(m_name, buffer);
            
            if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                strcpy(m_year, buffer);
                result = true;
            }
        }
    }
    
    return result;
}

Email::~Email() {
    delete[] m_name;
    delete[] m_email;
}

void EmailFile::setFilename(const char* filename)
{
    delete[] m_filename;
    m_filename = nullptr;
    if (filename)
    {
        m_filename = new char[strlen(filename) + 1];
        m_filename[0] = '\0';
        strcpy(m_filename, filename);
    }
}

void EmailFile::setEmpty()
{
    delete[] m_emailLines;
    delete[] m_filename;
    m_emailLines = nullptr;
    m_filename = nullptr;
    m_noOfEmails = 0;
}

bool EmailFile::setNoOfEmails() 
{
    
    bool isValid = false;
    ifstream file(m_filename);
    
    if (!file.is_open()) 
    {
        cout << "Failed to open file: " << m_filename << endl;
    }
    else
    {
        m_noOfEmails = 0;
        while (file) 
        {
            m_noOfEmails += (file.get() == '\n');
        }
        file.close();
        
        if (m_noOfEmails == 0)
        {
            delete[] m_filename;
            m_filename = nullptr;
        }
        else
        {
            m_noOfEmails++; // the very last line might not end with a new line, so this ensures that the last email is still counted.
            isValid = true;
        }
    }
    return isValid;
}

std::ostream& EmailFile::view(std::ostream& ostr) const
{
    if (m_filename) 
    {
        ostr << m_filename << endl;
        ostr.width(strlen(m_filename));
        ostr.fill('=');
        ostr << "=" << endl;
        ostr.fill(' ');
        for (int i = 0; i < m_noOfEmails; i++) 
        {
            ostr.width(35);
            ostr.setf(ios::left);
            ostr << m_emailLines[i].m_email;
            ostr.width(25);
            ostr << m_emailLines[i].m_name;
            ostr << "Year = " << m_emailLines[i].m_year << endl;
        }
    }
    
    return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
{
    return text.view(ostr);
}

void EmailFile::loadEmails()
{
    delete[] m_emailLines;
    m_emailLines = nullptr;
    if(m_filename){
        m_emailLines = new Email[m_noOfEmails];
        ifstream file(m_filename);
        for (int i = 0; i < m_noOfEmails; i++){
            if (!m_emailLines[i].load(file)) // i is added before calling the load function to ensure that the correct email is loaded, so that m_noOfEmails = i.
            {
				m_noOfEmails = i;
                break;
			}
        } 
    }
}

void EmailFile::copy(const EmailFile& src) // implementation of the copy logic
{
    if (src.m_emailLines && src.m_filename && src.m_noOfEmails)
    {
		m_noOfEmails = src.m_noOfEmails;
		m_filename = new char[strlen(src.m_filename) + 1];
		strcpy(m_filename, src.m_filename);
		m_emailLines = new Email[m_noOfEmails];
        for (int i = 0; i < m_noOfEmails; i++)
        {
			m_emailLines[i] = src.m_emailLines[i];
		}
	}
}
                
EmailFile::operator bool()const
{
    return m_emailLines && m_filename && m_noOfEmails;
}
                
EmailFile::EmailFile()
{
     m_emailLines = nullptr;
    m_filename = nullptr;
      m_noOfEmails = 0;
}

EmailFile::~EmailFile()
{
    delete[] m_emailLines;
	delete[] m_filename;
}

EmailFile::EmailFile(const char* filename)
{
    if (filename)
    {
        setFilename(filename);
        if (setNoOfEmails())
        {
            for (int i = 0; i < m_noOfEmails; i++)
            {
                loadEmails();
            }
        }
        else
        {
            setEmpty();
        }
	}
    else
    {
        setEmpty();
    }
}

EmailFile::EmailFile(const EmailFile& src) // Copy constructor
{
	copy(src); // localization
}


EmailFile& EmailFile::operator=(const EmailFile& src) // Copy assignment operator
{
    if (this != &src)
    {
		setEmpty();
		copy(src); // localization
	}
	return *this;
}

bool EmailFile::saveToFile(const char* filename) const
{
    if(filename)
    {
        ofstream file(filename);
        
        if (!file.is_open())
        {
            cout << "Error: Could not open file: " << filename << endl;
            return false;
        }
        else
        {
            /*It looks at each email saved in its memory (each one is an "Email" object in a big list called "m_emailLines").
             For every email, it writes down the details following the CSV format to the file.*/
            for (int i = 0; i < m_noOfEmails; i++)
            {
                file << m_emailLines[i].m_email << ',' << m_emailLines[i].m_name << "," << m_emailLines[i].m_year << endl;
            }
            file.close();
            return true;
        }
    }
    return false;
}

void EmailFile::fileCat(const EmailFile& obj, const char* name) // merges emails from another EmailFile object into the current object and optionally renames the resulting file
{
    if (obj) 
    {
        Email* temp = new Email[m_noOfEmails + obj.m_noOfEmails];
        for (int i = 0; i < m_noOfEmails; i++)
        {
            temp[i] = m_emailLines[i];
        }
        for (int i = m_noOfEmails; i < m_noOfEmails + obj.m_noOfEmails; i++)
        {
            temp[i] = obj.m_emailLines[i - m_noOfEmails];
        }
        delete[] m_emailLines;
        m_emailLines = temp;
    
    	m_noOfEmails += obj.m_noOfEmails;

        if (name) // if name is valid, then the file is renamed to the new name
        {
			delete[] m_filename;
			m_filename = new char[strlen(name) + 1];
			strcpy(m_filename, name);
		}
    }
  
    if(m_filename)
    {
        ofstream file(m_filename);
        for (int i = 0; i < m_noOfEmails; i++)
        {
            file << m_emailLines[i].m_email << ',' << m_emailLines[i].m_name << "," << m_emailLines[i].m_year << endl;
        }
        file.close();
    }
}
}
                


