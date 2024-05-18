//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 4 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef GUEST_H
#define GUEST_H
namespace seneca
{
	struct Guest
	{
        char* m_firstName = nullptr;
        char* m_lastName = nullptr;
        bool m_adult = false;
        
	};

	// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
	void set(Guest& guest, const char* first, const char* last, int age);

	// Prints the guest name:
	// "Name Surname(child)"
	// The child flag is printed if the guest is not an adult
	// and if the names are not set, "Vacated!" is printed.
	void print(const Guest& guest);

	// books the guest information from the console:
	// Name: Jake<ENTER>
	// Lastname: Doe<ENTER>
	// Age: 10<ENTER>
	void book(Guest& guest);

	// vacates the guest by dallocating its memory.
	void vacate(Guest& guest);

}

#endif
