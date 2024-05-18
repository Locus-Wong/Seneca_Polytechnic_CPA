/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 1
 Module: Menu
 Filename: Menu.cpp
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
#include "Menu.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace seneca
{

Menu::Menu(const char* menuContent, int numberOfTabs):m_text(nullptr), m_noOfOptions(0), m_noOfTabs(numberOfTabs)
	{
		if (menuContent)
		{
			size_t len = strlen(menuContent);
			m_text = new char[len + 1]; //dynamically allocates memory to store the content pointed to by menuContent in the member variable m_text
			for (int i = 0; menuContent[i]; i++)
			{
				m_text[i] = menuContent[i];
				if (menuContent[i] == '\n')
				{
					m_noOfOptions++; // scans m_text to count the number of newline characters '\n'
				}
			}
			m_text[len] = '\0'; // manually add the null terminator
		}
		else
		{
			m_text = nullptr;
			m_noOfOptions = 0;
			m_noOfTabs = 0;
		}
	}
	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	int& Menu::operator>>(int& Selection)
	{
		Menu::display();
		bool isValid = false;
		while (!isValid)
		{
			cin >> Selection;
			if (cin.fail()) // if the input contains invalid characters
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Bad integer value, try again: ";
			}
			else
			{
					isValid = true;
					if (cin.get() == ' ') // check if there is a whitespace after the input
					{
						cout << "Only enter an integer, try again: ";
						isValid = false;
					}
					else if (Selection < 0 || Selection > m_noOfOptions) // Check if the input value is outside the acceptable range
					{
						cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfOptions << "]: ";
						isValid = false;
					}
			}
		}
		return Selection;
	}

	void Menu::display()
	{
		if (m_text && m_noOfOptions)
		{
				for (int i = 0; m_text[i]; i++)
				{
					if (i == 0 && m_noOfTabs) // insert the tabs for the first line
					{
						for (int i = 0; i < m_noOfTabs; i++)
						{
                            cout << "   ";
						}
					}
					if (m_text[i] == '\n' && m_noOfTabs) // insert the tabs for the subsequent lines
					{
						cout << m_text[i]; // insert the newline first
						for (int i = 0; i < m_noOfTabs; i++)
						{
                            cout << "   ";
						}
					}
					else
					{
						cout << m_text[i]; // print the content
					}
				}
				cout << endl;
				if (m_noOfTabs) // insert the tabs for the 0- Exit
				{
					for (int i = 0; i < m_noOfTabs; i++)
					{
						cout << "   ";
					}
				}
				cout << "0- Exit" << endl;
				if (m_noOfTabs) // insert the tabs for the >
				{
					for (int i = 0; i < m_noOfTabs; i++)
					{
                        cout << "   ";
					}
				}
				cout << "> ";
		}
	}

}


