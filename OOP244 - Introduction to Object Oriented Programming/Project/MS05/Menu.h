/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 1
 Module: Menu
 Filename: Menu.h
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
#ifndef MENU_H
#define MENU_H

namespace seneca
{
	class Menu
	{
		char* m_text;
		int m_noOfOptions;
		int m_noOfTabs;

	public:
		Menu(const char* menuContent, int numberOfTabs = 0); //an optional integer numberOfTabs with a default value of 0
		~Menu();
		int& operator>>(int& Selection);
		void display();
		Menu& operator=(const Menu& M) = delete; // Makes sure the Menu can not assigned to another Menu object
		Menu(const Menu& M) = delete;  // Makes sure the Menu can not be copied to another Menu object
	};
}
#endif
