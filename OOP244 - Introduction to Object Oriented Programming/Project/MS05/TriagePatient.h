/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 5
 Module: TriagePatient
 Filename: TriagePatient.h
 Version 1.0
 Author   Tsz Wa Wong
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2024/4/02  Preliminary release
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 */
#ifndef TRIAGEPATIENT_H
#define TRIAGEPATIENT_H
#include <iostream>
#include "Patient.h"
namespace seneca
{
	class TriagePatient : public Patient
	{
		static int nextTriageTicket;
		char* m_symptoms{}; // dynamically hold the symptoms of the arriving patient for the triage center.
	public:
		TriagePatient();
		// Rule of 3
		~TriagePatient(); // destructor
		TriagePatient(const TriagePatient& TP); // copy constructor
		TriagePatient& operator=(const TriagePatient& TP); // copy assignment
		char type()const;
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);


	};

}

#endif
