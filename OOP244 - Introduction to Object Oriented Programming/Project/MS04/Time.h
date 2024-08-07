/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 4
 Module: Time
 Filename: Time.h
 Version 2.0
 Author   Tsz Wa Wong
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2024/3/13  Preliminary release
 2024/3/16  Delete the useless copy constructor
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 */
#ifndef TIME_H
#define TIME_H
#include <iostream>
namespace seneca {
	const size_t MAX_DIGITS_MINS = 22; //20 digits for hours and minutes in total
	class Time
	{
        unsigned int m_mins; // already use min = 0u to initialize to 0

	public:
		Time& reset();
		Time(unsigned int min = 0u); //sets the number of minutes held in the object to the value provided in the min parameter. If no value is provided, it defaults to zero
        std::ostream& displayMethod(std::ostream& ostr = std::cout) const;
        std::istream& readMethod(std::istream& istr = std::cin);
		operator unsigned int()const;
		Time& operator*= (int val);
		Time& operator-= (const Time& D);
		Time operator-(const Time& T)const;
	};

	std::ostream& operator<<(std::ostream& ostr, const Time& T);
	std::istream& operator>>(std::istream& istr, Time& T);
}
#endif
