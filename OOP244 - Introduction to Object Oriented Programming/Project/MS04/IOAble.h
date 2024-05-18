/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 4
 Module: IOAble
 Filename: IOAble.h
 Version 1.0
 Author   Tsz Wa Wong
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2024/3/14  Preliminary release
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 */
#ifndef IOABLE_H
#define IOABLE_H
#include <iostream>
namespace seneca
{
	class IOAble
	{
	public:
		virtual std::ostream& write(std::ostream& ostr)const = 0; // = 0 : enforces the implementation of input and output methods to its derived classes
		virtual std::istream& read(std::istream& istr) = 0; // = 0 : enforces the implementation of input and output methods to its derived classes
		virtual ~IOAble() = default; // empty virtual destructor
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& IO);
	std::istream& operator>>(std::istream& istr, IOAble& IO);
}
#endif
