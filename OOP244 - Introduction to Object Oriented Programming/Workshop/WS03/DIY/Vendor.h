//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 7 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Some parts of the code in Utils are references to my professor's.
#ifndef VENDOR_H
#define VENDOR_H
#include "Icecream.h"
namespace seneca
{

	class Vendor
	{
        Icecream* m_orders{nullptr};
        int m_noOfOrders{};
		void deallocate();
		double m_totalPrice{};
        double tax{};
        double m_totalPriceWithTax{};
		public:
			void setEmpty();
			void takeOrders();
			void displayOrders();
			void clearData();
	};
}
#endif
