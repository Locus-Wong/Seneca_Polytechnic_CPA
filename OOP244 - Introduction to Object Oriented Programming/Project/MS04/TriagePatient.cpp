/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 4
 Module: TriagePatient
 Filename: TriagePatient.cpp
 Version 1.0
 Author   Tsz Wa Wong
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2024/3/23  Preliminary release
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TriagePatient.h"
using namespace std;
namespace seneca
{
	int TriagePatient::nextTriageTicket = 1;
	
	TriagePatient::TriagePatient(): Patient(nextTriageTicket)
	{
		nextTriageTicket++;
	}

	TriagePatient::~TriagePatient()
	{
		delete [] m_symptoms;
        m_symptoms = nullptr;
	}

	TriagePatient::TriagePatient(const TriagePatient& TP) : Patient(TP) // copy constructor // use base class copy constructor to initialize the part of base class
	{
		if (TP.m_symptoms)
		{
			delete[] m_symptoms;
			m_symptoms = new char[strlen(TP.m_symptoms) + 1];
			strcpy(m_symptoms, TP.m_symptoms);
		}
		else
		{
			m_symptoms = nullptr; // initialize the only data member of TriagePatient
		}
	}

	TriagePatient& TriagePatient::operator=(const TriagePatient& TP) // copy assignment
	{
		if (this != &TP)
		{
			Patient::operator=(TP); // call the base class copy assignment
			delete[] m_symptoms;
			m_symptoms = new char[strlen(TP.m_symptoms) + 1];
			strcpy(m_symptoms, TP.m_symptoms);
		}
		return *this;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (&ostr == &cout)
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << "Symptoms: " << m_symptoms << endl;
		}
		else if (&ostr == &clog)
		{
			Patient::write(ostr);
		}
		else
		{
			Patient::write(ostr);
			ostr << ',' << m_symptoms;
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		if (m_symptoms)
		{
			delete[] m_symptoms;
			m_symptoms = nullptr;
		}
		
		// Read from console
		if (&istr == &cin)
		{
			Patient::read(istr);
			char buf[512]{};
			cout << "Symptoms: ";
			istr.get(buf, 512); //reads up to 511 characters, 1 for null terminator
			m_symptoms = new char[strlen(buf) + 1];
			strcpy(m_symptoms, buf);	
			istr.ignore(1000, '\n');
		}
		else
		{
			// Read from csv.file
			Patient::read(istr);
			istr.ignore(); //discards the comma from the input stream
			char buf[1000]{};
			istr.get(buf, 1000,'\n');
			size_t len = strlen(buf);
			if (len > 511) // If the symptoms name is too long, manually set the 512th character to null terminator
			{
				buf[511] = '\0';
				len = 511;
			}
			m_symptoms = new char[strlen(buf) + 1];
			strcpy(m_symptoms, buf);
			nextTriageTicket = Patient::number() + 1;
		}
		return istr;
	}

}
