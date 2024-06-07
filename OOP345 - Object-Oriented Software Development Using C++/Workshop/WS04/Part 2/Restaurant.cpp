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
#include "Restaurant.h"
#include "Reservation.h"
namespace seneca{

Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : m_cnt{cnt} { // 2-arg constructor
    m_reservations = new Reservation*[m_cnt];
    for (size_t i = 0; i < m_cnt; i++) {
        m_reservations[i] = new Reservation(*reservations[i]); // make a copy of all reservations
    }
}

Restaurant::Restaurant(const Restaurant& src): m_reservations{}, m_cnt{}{ // copy constructor
    operator=(src);
}

Restaurant& Restaurant::operator= (const Restaurant& src){ // copy assignment
    if(this != &src){
        for (size_t i = 0; i < m_cnt; i++){
            delete m_reservations[i];
        }
        delete[] m_reservations;
        m_cnt = src.m_cnt;
        m_reservations = new Reservation* [m_cnt];
        for (size_t i = 0; i < m_cnt; i++){
            m_reservations[i] = new Reservation(*src.m_reservations[i]); // make a copy of all reservations
        }
    }
    return *this;
}

Restaurant::Restaurant(Restaurant&& src){ // move constructor
    operator=(std::move(src));
}

Restaurant& Restaurant::operator= ( Restaurant&& src){ // move assignment
    if(this != &src){
        for (size_t i = 0; i < m_cnt; i++){
            delete m_reservations[i];
        }
        delete[] m_reservations;
        m_cnt = src.m_cnt;
        m_reservations = src.m_reservations;
        src.m_reservations = nullptr;
        src.m_cnt = 0;
    }
    return *this;
}

size_t Restaurant::size() const{
    return  m_cnt;
}

Restaurant::~Restaurant(){
    // Since restuarant compose reservations, we have to delete the child objects which are reservations
    for(size_t i = 0; i < m_cnt; i++){
        delete m_reservations[i];
    }
    delete[] m_reservations;
}

std::ostream& operator << (std::ostream& ostr, const Restaurant& rest){
    static int CALL_CNT = 0;
    CALL_CNT++;
    if(rest.size() == 0){
        ostr << "--------------------------" << std::endl
        <<"Fancy Restaurant (" << CALL_CNT << ")" << std::endl
        <<"--------------------------"<< std::endl
        <<"This restaurant is empty!" << std::endl
        <<"--------------------------" << std::endl;
    }else{
        ostr << "--------------------------" << std::endl
        <<"Fancy Restaurant (" << CALL_CNT << ")" << std::endl
        <<"--------------------------"<< std::endl;
        for (size_t i = 0; i < rest.m_cnt; i++){
            ostr<< *rest.m_reservations[i];
        }
        ostr <<"--------------------------" << std::endl;
    }
    return ostr;
}
}
