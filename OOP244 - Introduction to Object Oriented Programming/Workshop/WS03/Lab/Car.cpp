//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 3 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca 
{
    bool Car::isEmpty() const
    {
        if (m_makeModel == nullptr || m_serviceDesc == nullptr || m_makeModel[0] == '\0' || m_serviceDesc[0] == '\0')
        {
            return true;
        }

        return false;
    }

    void Car::setEmpty()
    {
        m_licencePlate[0] = '\0';
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
        m_cost = 0.0;
    }

    void Car::deallocateMemory()
    {
        delete[] m_makeModel;
        m_makeModel = nullptr;
        delete[] m_serviceDesc;
        m_serviceDesc = nullptr;
    }

    void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost)
    {
        deallocateMemory();
        setEmpty();
        
        if (plateNo != nullptr && plateNo[0] != '\0' && carMakeModel != nullptr && carMakeModel[0] != '\0' && serviceDesc != nullptr && serviceDesc[0] != '\0')
        {
            strcpy(m_licencePlate, plateNo);

            m_makeModel = new char[strlen(carMakeModel) + 1];
            strcpy(m_makeModel, carMakeModel);

            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_serviceDesc, serviceDesc);

            m_cost = serviceCost;
        }
    }

    void Car::display() const
    {
        if (!isEmpty())
        {
            cout.setf(ios::left);
            cout.width(15);
            cout << "License Plate:";
            cout.unsetf(ios::left);
            cout.width(20);
            cout << m_licencePlate << endl;

            cout.setf(ios::left);
            cout.width(15);
            cout << "Model:";
            cout.unsetf(ios::left);
            cout.width(20);
            cout << m_makeModel << endl;

            cout.setf(ios::left);
            cout.width(15);
            cout << "Service Name:";
            cout.unsetf(ios::left);
            cout.width(20);
            cout << m_serviceDesc << endl;

            cout.setf(ios::left);
            cout.width(15);
            cout << "Service Cost:";
            cout.unsetf(ios::left);
            cout.setf(ios::fixed);
            cout.width(20);
            cout.precision(2);
            cout << m_cost << endl;
         }
    }

}

