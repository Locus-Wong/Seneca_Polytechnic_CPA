//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 3 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Car.h"

namespace seneca
{
    class Customer{

        private:
            int m_id;
            char* m_name;
            const Car* m_car;


        public:
            bool isEmpty() const;
            void setEmpty();
            void deallocateMemory();
            void set(int customerId, const char* name, const Car* car);
            void display() const;
            const Car& car()const;
        };
}
#endif
