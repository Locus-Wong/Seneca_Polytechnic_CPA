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
#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H
#include <iostream>
namespace seneca{
    class Reservation;
    class ConfirmationSender{
        const Reservation** m_reservations{};
        size_t  m_cnt{};
    public:
        ConfirmationSender() = default;
        ConfirmationSender(const ConfirmationSender& src); // copy constructor
        ConfirmationSender& operator=(const ConfirmationSender& src); // copy assignment
        ConfirmationSender(ConfirmationSender&& src); // move constructor
        ConfirmationSender& operator=(ConfirmationSender&& src); // move assignment
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        ~ConfirmationSender();
        friend std::ostream& operator<< (std::ostream& ostr, const ConfirmationSender& confirmSender);
    };

}


#endif
