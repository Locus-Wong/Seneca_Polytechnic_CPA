/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 4
 Module: TestPatient
 Filename: TestPatient.cpp
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
#include <iostream>
#include "TestPatient.h"
using namespace std;
namespace seneca
{
	int TestPatient::nextTestTicket = 1; // initialize it to 1
	char TestPatient::type() const
	{
		return 'C';
	}

	TestPatient::TestPatient() : Patient(nextTestTicket)
	{
		nextTestTicket++;
	}

	std::ostream& TestPatient::write(std::ostream& ostr) const
	{
		if (&ostr == &cout)
		{
			ostr << "Contagion TEST" << endl;
		}
		Patient::write(ostr);
		return ostr;
	}

	std::istream& TestPatient::read(std::istream& istr)
	{
		Patient::read(istr);
		if (&istr != &cin)
		{
			nextTestTicket = Patient::number() + 1;
		}
		return istr;
	}


}
