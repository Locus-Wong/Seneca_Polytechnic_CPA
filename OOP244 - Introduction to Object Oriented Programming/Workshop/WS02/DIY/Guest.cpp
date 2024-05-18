//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 4 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Guest.h"
using namespace std;
namespace seneca
{
	void set(Guest& guest, const char* first, const char* last, int age)
	{
        if (first && last && first[0] != '\0' && last[0] != '\0')
        {
            guest.m_firstName = new char[strlen(first) + 1];
            guest.m_lastName = new char[strlen(last) + 1];
        }
        
        if (guest.m_firstName && guest.m_lastName && age)
        {
            strcpy(guest.m_firstName, first);
            strcpy(guest.m_lastName, last);
            guest.m_adult = (age >= 18);
        }
        else
        {
            delete[] guest.m_firstName;
            delete[] guest.m_lastName;
            guest.m_firstName = guest.m_lastName = nullptr;
            guest.m_adult = false;
        }
	}

	void print(const Guest& guest)
	{
        if (guest.m_firstName == nullptr && guest.m_lastName == nullptr)
        {
            cout << "Vacated!\n";
        }
        else
        {
            cout << guest.m_firstName << " " << guest.m_lastName;
            if (guest.m_adult == false)
            {
                cout << "(Child)\n";
            }
            else
            {
                cout << "\n";
            }
        }

	}

	void book(Guest& guest)
	{
		char firstName[100];
		char lastName[100];
		int age;

		cout << "Name: ";
		cin >> firstName;
		cout << "Lastname: ";
		cin >> lastName;
		cout << "Age: ";
		cin >> age;
		set(guest, firstName, lastName, age);
        
	}

	void vacate(Guest& guest)
	{
        delete [] guest.m_firstName;
        guest.m_firstName = nullptr;
        delete [] guest.m_lastName;
        guest.m_lastName = nullptr;
        guest.m_adult = false;
	}
}
