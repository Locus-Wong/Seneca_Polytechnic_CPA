/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 6 June 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H
#include <iostream>
#include <string>
namespace seneca{

class Reservation{
    std::string m_reservationID{};
    std::string m_reservationName{};
    std::string m_email{};
    int m_numOfPeople{};
    int m_day{};
    int m_hour{};
    
public:
    Reservation(const std::string& res);
    void update(int day, int time);
    friend std::ostream& operator << (std::ostream& ostr, const Reservation& res);
    friend std::string trim(const std::string& str); // custom trim function
};
}

#endif
