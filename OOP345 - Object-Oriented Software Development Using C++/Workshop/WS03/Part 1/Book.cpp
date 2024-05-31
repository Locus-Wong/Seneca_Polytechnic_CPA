/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 30 May 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;
namespace seneca {

Book::Book() : m_title{}, m_numChapters{}, m_numPages{}{}

Book::Book(const string& title, unsigned nChapters, unsigned nPages): m_title{title}, m_numChapters{nChapters}, m_numPages{nPages}{}

bool Book::operator>(const Book& src) const{
    
    return (static_cast<double>(m_numPages)/m_numChapters > static_cast<double>(src.m_numPages)/src.m_numChapters);
}

bool Book::operator<(const Book& src) const{
    
    return (static_cast<double>(m_numPages)/m_numChapters < static_cast<double>(src.m_numPages)/src.m_numChapters);
}

ostream& Book::print(ostream& os) const{
    if (m_title != "" && m_numPages && m_numPages){
        os.setf(ios::right);
        if(m_numChapters > 9) {
            os.width(49);
        }
        else{
            os.width(50);
        }
        os << m_title <<",";
        os << m_numChapters <<"," ;
        os << m_numPages << " | ";
        os.unsetf(ios::right);
        os.setf(ios::left);
        os.setf(ios::fixed);
        os.precision(6);
        os << "(";
        os.width(9);
        os << static_cast<double>(m_numPages)/m_numChapters;
        os.width(5);
        os << ")";
        os.unsetf(ios::fixed);
    }else{
        os << "|";
        os.width(18);
        os << " Invalid book data";
    }
    return os;
}

ostream& operator<<(ostream& os, const Book& bk){
    
    return bk.print(os);
}

}

