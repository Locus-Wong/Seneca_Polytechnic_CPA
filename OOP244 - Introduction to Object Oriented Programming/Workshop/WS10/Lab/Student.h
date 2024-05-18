/***********************************************************************
// OOP244 Workshop 10 p1: Student module header file
//
// File: Student.h
// Version 1.0
// Date: Oct 4, 2023
// Author: Jeevan Pant
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Module supplied
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include<cstring>
#include<string>
#include "Book.h"

namespace seneca {
	class Book;
	class Student {
		int m_id;
		char m_name[256];
		float m_marks[32];
		int m_numCourses;
		char m_program[4]; // program student enrolled in
	public:
		Student();
		Student(int id, const char* name, const char* program, const float* marks, int num);
		const char* Program() const;
		bool operator==(int) const;
		bool operator==(double) const;
		bool operator==(const Book& bk) const;
		std::ostream& display(std::ostream&) const;
	};
	std::ostream& operator<<(std::ostream&, const Student&);

}

#endif
