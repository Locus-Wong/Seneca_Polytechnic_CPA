//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 4 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Room.h"
using namespace std;
namespace seneca
{
    void set(Room& room, size_t numberOfGuests, const char* roomNumber)
    {
        if (roomNumber)
        {
            strcpy(room.m_roomNumber, roomNumber);
        }
        if (numberOfGuests)
        {
            room.m_noOfGuests = numberOfGuests;
            room.m_guests = new Guest[room.m_noOfGuests];
        }
        
        if (!room.m_guests)
        {
            delete[] room.m_guests;
            room.m_guests = nullptr;
        }
        
        
    }

void print(const Room& room)
{
    if(room.m_roomNumber[0] != '\0' && room.m_noOfGuests != 0)
    {
        cout << "Room Number: " << room.m_roomNumber << endl;
    }
    for (size_t i = 0; i < room.m_noOfGuests; i++)
    {
        cout << "    ";
        print(room.m_guests[i]);
    
    }
		
    if (room.m_noOfGuests == 0 && room.m_guests == nullptr)
    {
        cout << "Empty Room!" << endl;
    }
    
}

	void book(Room& room)
	{
		cout << "Room number: ";
        cin >> room.m_roomNumber;
        cout << "Number of guests: ";
        cin >> room.m_noOfGuests;
        
        if (!room.m_guests)
        {
            room.m_guests = new Guest[room.m_noOfGuests];
        }
            
        for (size_t i = 0; i < room.m_noOfGuests; i++)
        {
            cout << i + 1 << ":" << endl;
            book(room.m_guests[i]);
        }
        
        
            
        
	}

	void vacate(Room& room)
    {
        
       
        
        for (size_t i = 0; i < room.m_noOfGuests; i++)
        {
            delete[] room.m_guests[i].m_firstName;
            delete[] room.m_guests[i].m_lastName;
            room.m_guests[i].m_firstName = nullptr;
            room.m_guests[i].m_lastName = nullptr;
        }
        delete[] room.m_guests;
        room.m_guests = nullptr;
        
        room.m_noOfGuests = 0;
    }

}

