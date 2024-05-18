/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 3
 Module: Patient
 Filename: Patient.cpp
 Version 1.0
 Author   Tsz Wa Wong
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2024/3/16  Preliminary release
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
using namespace std;
namespace seneca
{
	Patient::Patient(int ticketNumber)
    {
        m_ticket = ticketNumber; // m_patientName{nullptr} and m_OHIP{0} are already used to initialized the other two variables
    }
	
    void Patient::copy(const Patient& src) // localization
    {
        m_OHIP = src.m_OHIP;
        if(src.number() && src.time()) // check if the source ticket is valid
        {
            m_ticket = src.m_ticket;
        }
        if (src.m_patientName)
        {
            m_patientName = new char[strlen(src.m_patientName) + 1];
            strcpy(m_patientName, src.m_patientName);
        }
        else
        {
            m_patientName = nullptr;
        }
    }

    Patient::Patient(const Patient& P) // copy constructor
	{
		copy(P);
	};

	Patient& Patient::operator=(const Patient& P) // copy assignment
	{
       
		if (this != &P)
		{
            delete[] m_patientName;
			m_patientName = nullptr;
			copy(P);
		}
		return *this;
	}

    Patient::~Patient()
    {
        delete[] m_patientName;
        m_patientName = nullptr;
    }
	
	bool Patient::operator==(char c) const // compare the current object with a single character (the right operand)
	{
		return (type() == c);
	}

	bool Patient::operator==(const Patient& P) const // compare the current object to another patient
	{
		return (type() == P.type());
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime(); //sets the time of the patient's ticket to the current time
	}

	Time Patient::time() const
	{
		return m_ticket.time(); //returns the time of the patient's ticket
	}

	int Patient::number() const
	{
		return m_ticket.number(); //returns the number of the patient's ticket
	}

	Patient::operator bool() const
	{
		return m_patientName && m_OHIP && time() && number();
	}

	Patient::operator const char* () const
	{
		return m_patientName; //returns the address of the patient's name
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
        // clog
		if (&ostr == &clog)
		{
			if (!(*this)) // check if the current object is valid
			{
				ostr << "Invalid Patient Record";
			}
			else 
			{
				ostr.width(53);
				ostr.fill('.');
				ostr.setf(ios::left);
				ostr << m_patientName;
				ostr << m_OHIP;
				ostr.fill(' ');
				ostr.width(5);
				ostr.unsetf(ios::left);
				ostr << number();
				ostr << ' ';
				ostr << time();
			}
		}
        // cout
		if(&ostr == &cout)
		{
			if (!(*this)) // check if the current object is valid
			{
				ostr << "Invalid Patient Record" << endl;
			}
			else 
			{
				ostr << m_ticket << endl << m_patientName << ", OHIP: " << m_OHIP << endl;
			}
		}
        // cerr
		if(&ostr != &cout && &ostr != &clog)
		{
			ostr << type() << ',' << m_patientName << ',' << m_OHIP << ',';
			m_ticket.write(ostr);
		}
	return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
        // Read from console
		if(&istr == &cin)
		{
			bool isValid = false;
            char buf[51]{};
			cout << "Name: ";
			istr.get(buf, 51); //reads up to 50 characters, 1 for null terminator
            if(m_patientName)
            {
                delete[] m_patientName;
				m_patientName = nullptr;
            }
			m_patientName = new char[strlen(buf) + 1];
			strcpy(m_patientName, buf);
			istr.ignore(1000,'\n');
			cout << "OHIP: ";
			while (!isValid)
			{
				istr >> m_OHIP;
				if (istr.fail()) // if the input contains invalid characters
				{
					istr.clear();
					istr.ignore(1000, '\n');
					cout << "Bad integer value, try again: ";
				}
				else
				{
					isValid = true;
					if (cin.get() == ' ') // check if there is a whitespace after the input
					{
						cout << "Only enter an integer, try again: ";
						isValid = false;
					}
					else if (m_OHIP < 100000000 || m_OHIP > 999999999) // Check if the input value is outside the acceptable range
					{
						cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
						isValid = false;
					}
				}
			}
		}
		else 
		{
            // Read from csv.file
            char buf[1000]{};
			istr.getline(buf, 1000, ',');
			size_t len = strlen(buf);
			if (len > 50) // If the patient name is too long, manually set the 51st character to null terminator
			{
				buf[50] = '\0';
				len = 50;
			}
            if(m_patientName)
            {
                delete[] m_patientName;
            }
			m_patientName = new char[len + 1];
			strcpy(m_patientName, buf);
			istr >> m_OHIP;
			istr.ignore(); //discards the comma from the input stream
			m_ticket.read(istr);
		}
		return istr;
	}
}
