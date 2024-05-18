//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 7 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Some parts of the code in Utils are references to my professor's.
#ifndef ICECREAM_H
#define ICECREAM_H
#include <iostream>
namespace seneca
{
	class Icecream
	{
        int m_selectedflavour{};
        std::string m_flavour[6] = { "", "Chocolate", "Strawberry", "Mango", "Tutti fruit", "Almond crunch" };
        int m_scoops{};
        bool m_wafer_cone = false;
        double m_scoopsPrice{};
        double m_flavourPrice{};
        double m_waferPrice{};
       
		public:
        double m_Price{};
			void getOrder();
			void printOrder();
            
	};
}

#endif
