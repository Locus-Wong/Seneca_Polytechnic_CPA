/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 1
 Module: Time
 Filename: Time.cpp
 Version 1.0
 Author   Tsz Wa Wong
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2024/3/13  Preliminary release
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Time.h"
#include "Utils.h"
#include <cstring>
using namespace std;
namespace seneca
{
	Time& Time::reset()
	{
		m_mins = U.getTime(); //resets the Time object to the current time using the U.getTime() method
		return *this; //returns a reference to the current object
	}

    ostream& Time::displayMethod(ostream& ostr) const
    {
        //If the hours or minutes are single-digit numbers, it pads them with a leading zero
        ostr.width(2);
        ostr.fill('0');
        ostr << m_mins / 60;
        ostr << ":";
        ostr.width(2);
        ostr.fill('0');
        ostr << m_mins % 60;
        return ostr;
    }
	
	istream& Time::readMethod(istream& istr)
	{
		bool isValid = false;
		size_t indexOfColon = 0;
		char buf[MAX_DIGITS_MINS];
		istr >> buf;
		if (buf[0] != '\0')
		{
			size_t len = strlen(buf);
			for (size_t i = 0; i < len; i++)
			{
				if (buf[i] == ':' && i != (len - 1))
				{
					isValid = true; // if there is : in the middle of the input, set isValid to be true
					indexOfColon = i;
				}
			}
		}
		if (isValid)
		{
			char hoursBuf[MAX_DIGITS_MINS];
			strncpy(hoursBuf, buf, indexOfColon); // copy the hours
			hoursBuf[indexOfColon] = '\0'; // manually add the null terminator
			char minsBuf[MAX_DIGITS_MINS];
			strcpy(minsBuf, buf + indexOfColon + 1); // copy the mins
			int hours = atoi(hoursBuf); // use atoi to convert char[] to int
			int mins = atoi(minsBuf); // use atoi to convert char[] to int
			m_mins = hours * 60 + mins;
		}
		else
		{
			istr.setstate(ios::failbit); // sets the istream object to a failure state
		}
		return istr;
	}

	Time::operator unsigned int() const
	{
		return m_mins; //If a Time object is cast to an unsigned integer, it will return the number of minutes held in the object
	}

	Time& Time::operator*=(int val)
	{
		m_mins *= val; //multiplies the number of minutes held in the Time object by val
		return *this; //returns a reference to the current object
	}

	Time& Time::operator-=(const Time& D)
	{
		if (D.m_mins > m_mins) // If the result would be negative, it adds 24 hours (or 1440 minutes) to ensure the result is positive
		{
			m_mins = m_mins + 24 * 60 - D.m_mins;
		}
		else
		{
			m_mins -= D.m_mins;
		}
		return *this;
	}

	Time Time::operator-(const Time& T) const
	{
		return Time(*this) -= T; // use copy constructor to create a temp object of type T as this function should not modify the current object
	}
	
	std::ostream& operator<<(std::ostream& ostr, const Time& T)
	{
        return T.displayMethod(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& T)
	{
		return T.readMethod(istr); // E.readMethod(istr);
	}

}



