/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 17 May 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "FoodOrder.h"
using namespace std;

double g_taxrate = 0.0; // global variables
double g_dailydiscount = 0.0; // global variables

namespace seneca
{
    FoodOrder::FoodOrder()
    {
        m_custName[0] = '\0';
        m_foodDescription = nullptr;
        m_price = 0;
        m_dailySpecial = false;
        
    }

	void FoodOrder::read(std::istream& istr)
	{
		char temp[10000];
		istr.getline(m_custName, 10, ',');
		istr.getline(temp, 10000, ',');
        delete[] m_foodDescription; // *** delete the old memoey, before assign new memory
		m_foodDescription = new char[strlen(temp) + 1];
		strcpy(m_foodDescription, temp);
		istr >> m_price;
		istr.ignore();
		m_dailySpecial = (istr.get() =='Y'? 1:0); // check if the character is Y or N, then set m_dailySpecial to true or false respectively
		istr.ignore();
	}
	
	void FoodOrder::display() const
	{
		static int count = 1;
		cout.setf(ios::left);
		cout.width(2);
		cout << count << ". ";
        count++;
		if (m_custName[0])
		{
			cout.setf(ios::left);
			cout.width(10);
			cout << m_custName << "|";
			cout.width(25);
			cout << m_foodDescription << "|";
			cout.width(12);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price * (1 + g_taxrate) << "|";
			if (m_dailySpecial)
			{
				cout.unsetf(ios::left);
				cout.width(13);
				cout.precision(2);
				cout << (m_price * (1 + g_taxrate) - g_dailydiscount);			
			}
			cout << endl;
		}
		else
		{
			cout << "No Order" << endl;
		}
	}

	FoodOrder::FoodOrder(const FoodOrder& src)
	{
        *this = src;
	}

	FoodOrder& FoodOrder::operator=(const FoodOrder& src)
	{
		if (this != &src)
		{
			strcpy(m_custName, src.m_custName);
			m_price = src.m_price;
			m_dailySpecial = src.m_dailySpecial;
			delete[] m_foodDescription;
			if (src.m_foodDescription)
			{
				m_foodDescription = new char[strlen(src.m_foodDescription) + 1];
				strcpy(m_foodDescription, src.m_foodDescription);
			}
			else
			{
				m_foodDescription = nullptr;
			}
		}
		return *this;
	}

	FoodOrder::~FoodOrder()
	{
		delete[] m_foodDescription;
		m_foodDescription = nullptr;
	}

}
