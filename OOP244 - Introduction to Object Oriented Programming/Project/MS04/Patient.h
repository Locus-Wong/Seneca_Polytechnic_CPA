/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 4
 Module: Patient
 Filename: Patient.h
 Version 2.0
 Author   Tsz Wa Wong
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2024/3/16  Preliminary release
 2024/3/23 Change from ~Patient(); to virtual ~Patient(); to ensure most updated destructor is called
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 */
#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
namespace seneca {
	class Patient :public IOAble
	{
        char* m_patientName{nullptr}; // hold the address of a dynamically allocated C-string with max 50 characters
        int m_OHIP{0}; // hold the 9 digits OHIP number of the patient
        Ticket m_ticket{0};
	public:
		Patient(int ticketNumber);
        void copy(const Patient& src); // copy logic
		Patient(const Patient& P); // copy constructor
		Patient& operator=(const Patient& P); // copy assignment
        virtual ~Patient();
        
        virtual char type()const = 0; // pure virtual function -> Patient class is abstract
		// Operator== Overloads
		bool operator==(char c)const;
		bool operator==(const Patient& P)const;
		// Modifier method
		void setArrivalTime();
		// Query methods
		Time time()const;
		int number()const;
		// Cast Overloads
		operator bool()const;
		operator const char*()const;
        // Pure virtual function overwrites
		std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
	};
}
#endif
