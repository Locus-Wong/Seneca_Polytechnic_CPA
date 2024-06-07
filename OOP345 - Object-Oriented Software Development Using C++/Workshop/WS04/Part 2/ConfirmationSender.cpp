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
#include <iostream>
#include "ConfirmationSender.h"
#include "Reservation.h"

namespace seneca{

ConfirmationSender::ConfirmationSender(const ConfirmationSender& src){ // copy constructor
    operator=(src);
}

ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src){ // copy assignment
    if(this != &src){
        delete[] m_reservations;
        m_cnt = src.m_cnt;
        m_reservations = new const Reservation* [m_cnt];
        for (size_t i = 0; i < m_cnt; i++) {
            m_reservations[i] = src.m_reservations[i];
        }
    }
    return *this;
}

ConfirmationSender::ConfirmationSender(ConfirmationSender&& src){ // move constructor
    operator=(std::move(src));
}

ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src){ // move assignment
    if(this != &src){
        delete[] m_reservations;
        m_cnt = src.m_cnt;
        m_reservations = src.m_reservations;
        src.m_reservations = nullptr;
        src.m_cnt = 0;
    }
    return *this;
}

ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
    bool found{};
    if(m_cnt){
        for(size_t i = 0; i < m_cnt ; i++){
            if(m_reservations[i] == &res){
                found = true;
            }
        }
        if(!found){
            const Reservation** temp = new const Reservation* [m_cnt + 1];
            for (size_t i = 0; i < m_cnt; i++) {
                temp[i] = m_reservations[i];
            }
            temp[m_cnt] = &res;
            delete[] m_reservations;
            m_reservations = temp;
            m_cnt++;
        }
        
    }
    else{
        m_reservations = new const Reservation* [m_cnt + 1];
        m_reservations[m_cnt] = &res;
        m_cnt++;
    }
    return *this;
}

ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
    size_t foundIndex = 10000;
    if(m_cnt){
        for(size_t i = 0; i < m_cnt && (foundIndex == 10000) ; i++){
            if(m_reservations[i] == &res){
                foundIndex = i;
            }
        }
        if(foundIndex != 10000){
            const Reservation** temp = new const Reservation* [m_cnt - 1];
            for (size_t i = 0; i < foundIndex; i++) {
                temp[i] = m_reservations[i];
            }
            for (size_t i = foundIndex + 1; i < m_cnt; i++){
                temp[i - 1] = m_reservations[i];
            }
            delete[] m_reservations;
            m_reservations = temp;
            m_cnt--;
        }
    }
    return *this;
}

ConfirmationSender::~ConfirmationSender(){
    delete[] m_reservations;
}

std::ostream& operator<< (std::ostream& ostr, const ConfirmationSender& confirmSender){
    
    if (confirmSender.m_cnt){
        ostr << "--------------------------" << std::endl
        << "Confirmations to Send" << std::endl
        << "--------------------------" << std::endl;
        for (size_t i = 0; i < confirmSender.m_cnt; i++){
            ostr << *confirmSender.m_reservations[i] ;
        }
        ostr << "--------------------------" << std::endl;
    }else{
        ostr << "--------------------------" << std::endl
        << "Confirmations to Send" << std::endl
        << "--------------------------" << std::endl
        << "There are no confirmations to send!" << std::endl
        << "--------------------------" << std::endl;
    }
    return ostr;
}

}

