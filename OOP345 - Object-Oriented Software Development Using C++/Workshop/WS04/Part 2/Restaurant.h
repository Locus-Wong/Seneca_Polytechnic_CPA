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
#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H
#include <iostream>
namespace seneca{
class Reservation;
class Restaurant{
    Reservation** m_reservations{};
    size_t m_cnt{};
public:
    Restaurant(const Reservation* reservations[], size_t cnt); // 2-arg constructor
    Restaurant(const Restaurant& src); // copy constructor
    Restaurant& operator=(const Restaurant& src); // copy assignment
    Restaurant(Restaurant&& src); // move constructor
    Restaurant& operator=( Restaurant&& src); // move assignment
    size_t size() const;
    ~Restaurant();
    friend std::ostream& operator << (std::ostream& ostr, const Restaurant& rest);
};
}
#endif
