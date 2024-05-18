//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 7 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Some parts of the code in Utils are references to my professor's.
#include <iostream>
#include "Icecream.h"
#include "Utils.h"
using namespace std;
namespace seneca
{
	void Icecream::getOrder()
	{
		cout << "Select flavour:" << endl;
		cout << "----------------" << endl;
		cout << "1: Chocolate" << endl;
		cout << "2: Strawberry" << endl;
		cout << "3: Mango" << endl;
		cout << "4: Tutti fruit" << endl;
		cout << "5: Almond crunch" << endl;
		cout << "----------------" << endl;
		cout << "> ";
		m_selectedflavour = ut.getInt(5);
		cout << "Number of Scoops (max 3)" << endl;
		cout << "> ";
		m_scoops = ut.getInt(3);
		m_flavourPrice = (m_selectedflavour == 1 ? double(m_scoops) : double(0));
		m_scoopsPrice = m_scoops * 5;
		cout << "Vanilla wafer cone?" << endl;
		cout << "(Y)es/(N)o > ";
		m_wafer_cone = ut.getLine();
		m_waferPrice = (m_wafer_cone ? double(5) : double(0));
		m_Price = (m_scoopsPrice + m_flavourPrice + m_waferPrice);
	}
	
	void Icecream::printOrder()
	{
		cout.setf(ios::fixed);
        cout.precision(2);
        cout.setf(ios::left);
        cout.width(15);
        cout << "Order details:";
        cout.unsetf(ios::left);
        cout.width(20);
        cout << "Price" << endl;
		cout << "-----------------------------------" << endl;
        
        
        cout.setf(ios::left);
        cout.width(18);
        cout << "Number of scoops, ";   // fixed width
        cout.width(1);  // max number of scoops is 3
        cout << m_scoops;
        cout.width(7);  // fixed width
        cout <<" total:";
        cout.width(9);  // 35 - 18 - 1 - 7 - 9
        cout.unsetf(ios::left);
        cout << m_scoopsPrice << endl;
        
        
		if (m_selectedflavour == 1)
		{
            cout.setf(ios::left);
            cout.width(m_flavour[m_selectedflavour].length());
            cout << m_flavour[m_selectedflavour];
            cout.width(35 - m_flavour[m_selectedflavour].length() - 4);
            cout << " flavour:";
            cout.unsetf(ios::left);
            cout.width(4); // max : 3.00 -> 4
            cout << m_flavourPrice << endl;
		}
		else 
		{
			cout << m_flavour[m_selectedflavour] << " flavour" << endl;
		}
        
        cout.setf(ios::left);
        cout.width(14); // fixed width
        cout << "Vanilla Wafer:";
        cout.unsetf(ios::left);
        cout.width(21); // 35 - 14
        cout << m_waferPrice << endl;
        
        cout.setf(ios::left);
        cout.width(6); // fixed width
        cout << "Price:";
        cout.unsetf(ios::left);
        cout.width(29); // 35 - 6
        cout << m_Price << endl;
        
	}




}
