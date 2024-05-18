/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 2
 Module: IOAble
 Filename: IOAble.cpp
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
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace seneca
{
	ostream& operator<<(ostream& ostr, const IOAble& IO)
	{
		return IO.write(ostr);
	}
	istream& operator>>(istream& istr, IOAble& IO)
	{
		return IO.read(istr);
	}
}
