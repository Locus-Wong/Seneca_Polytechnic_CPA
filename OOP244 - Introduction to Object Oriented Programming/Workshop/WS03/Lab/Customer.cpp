//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 3 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca
{
    bool Customer::isEmpty() const
    {
        if (m_name == nullptr || m_name[0] == '\0' || m_car == nullptr)
        {
            return true;
        }
        
        return false;
    }

    void Customer::setEmpty()
    {
        m_id = 0;
        m_name = nullptr;
        m_car = nullptr;
    }

    void Customer::deallocateMemory()
    {
        delete[] m_name;
        m_name = nullptr;
    }

    void Customer::set(int customerId, const char* name, const Car* car)
    {
        deallocateMemory();
        setEmpty();
        
        if (name != nullptr && name[0] != '\0' && car != nullptr)
        {
            m_id = customerId;
            
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
         
            m_car = car;
        }
    }

    void Customer::display() const
    {
        cout.setf(ios::left);
        cout.width(15);
        cout << "Customer ID:";
        cout.unsetf(ios::left);
        cout.width(20);
        cout << m_id << endl;
        
        cout.setf(ios::left);
        cout.width(15);
        cout << "First Name:";
        cout.unsetf(ios::left);
        cout.width(20);
        cout << m_name << endl;
        
        m_car->display();
    }

    const Car& Customer::car() const
    {
        return *m_car;
    }
}
