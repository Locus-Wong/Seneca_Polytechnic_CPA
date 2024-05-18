//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 4 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef ROOM_H
#define ROOM_H
#include "Guest.h"
namespace seneca
{
	struct Room
	{
        char m_roomNumber[6] = {0};
		size_t m_noOfGuests = 0;
        Guest* m_guests = nullptr;
        
	};

	// sets the Room by allocating a dynamic array of guests and setting the room number
	// (no validation is done for room number)
	void set(Room& room, size_t numberOfGuests, const char* roomNumber);

	// Prints the room number and names of the guests in the following lines with four 
	// spaces of indentaion 
	// See correct_output.txt for the exact format
	void print(const Room& room);

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room& room);

	// vacates the room by dallocating all the memory used.
	void vacate(Room& room);

}

#endif
