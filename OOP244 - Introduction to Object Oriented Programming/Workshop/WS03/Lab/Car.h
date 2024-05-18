//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 3 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef CAR_H
#define CAR_H

namespace seneca
{
	class Car
	{
        private:
            char m_licencePlate[9];
            char* m_makeModel;
            char* m_serviceDesc;
            double m_cost;

        public:
            bool isEmpty() const;
            void setEmpty();
            void deallocateMemory();
            void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
            void display() const;
	};
}
#endif
