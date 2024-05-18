/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 17 May 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca
{
	class FoodOrder
	{
		char m_custName[10]{};
		char* m_foodDescription{};
		double m_price{};
		bool m_dailySpecial{};
	
	public:
		FoodOrder();
		void read(std::istream& istr);
		void display() const;
		FoodOrder(const FoodOrder& src);
		FoodOrder& operator=(const FoodOrder& src);
		~FoodOrder();
	};
}
#endif
