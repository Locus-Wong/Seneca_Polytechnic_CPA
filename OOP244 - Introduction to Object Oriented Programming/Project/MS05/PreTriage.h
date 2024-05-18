/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 5
 Module: PreTriage
 Filename: PreTriage.cpp
 Version 1.0
 Author   Tsz Wa Wong
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2024/4/01  Preliminary release
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 */
#ifndef PRETRIAGE_H
#define PRETRIAGE_H
#include "Patient.h"
#include "Time.h"
namespace seneca
{
	const int maxNoOfPatients = 100;
	class PreTriage
	{
		Time m_averageWait_C;
		Time m_averageWait_T;

		Patient* m_lineup[maxNoOfPatients]{};

		char* m_fileName{}; // A C-string to hold the path and name of the data file.
		
		int m_noOfPatients{};
		
	

		// Private methods
		Time getWaitTime(const Patient& P) const;
		void setAverageWaitTime(const Patient& admitPatient);
		int indexOfFirstInLine(char patientType) const;
		void load(void);
		void save(void);
		void reg(void);
		void lineup(void);
		void admit(void);

	public:
		
		PreTriage(const char* fileName);
		bool run(void);
		~PreTriage();
	
		
	};
}
#endif
