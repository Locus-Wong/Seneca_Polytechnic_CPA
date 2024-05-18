/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 5
 Module: TestPatient
 Filename: TestPatient.h
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
#ifndef TESTPATIENT_H
#define TESTPATIENT_H
#include <iostream>
#include "Patient.h"
namespace seneca 
{
	class TestPatient : public Patient
	{
		// private: it is only accessible within the TestPatient class/module
		static int nextTestTicket; // static : all TestPatient objects share the same variable
	public:
			char type()const;
			TestPatient();
			std::ostream& write(std::ostream& ostr)const;
			std::istream& read(std::istream& istr);
	};
}
#endif
