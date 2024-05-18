//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 7 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Some parts of the code in Utils are references to my professor's.
#include "Vendor.h"
#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca
{

	void Vendor::setEmpty()
	{
		m_noOfOrders = 0;
		deallocate();
        m_totalPrice = 0;
        tax = 0;
        m_totalPriceWithTax = 0;
	}

	void Vendor::deallocate()
	{ 
		delete[] m_orders;
		m_orders = nullptr;
	}

	void Vendor::takeOrders()
	{
        cout << "Seneca Icecream shop" << endl;
        cout << "          @" << endl;
        cout << "        (' .)" << endl;
        cout << "       (*.`. )" << endl;
        cout << "        \\###/" << endl;
        cout << "         \\#/" << endl;
        cout <<"          V" << endl;
        
		cout << "How many Icecreams?" << endl;
        cout << "> ";
		m_noOfOrders = ut.getInt();
		m_orders = new Icecream[m_noOfOrders];

		for( int i = 0; i < m_noOfOrders; i++ )
		{
			cout <<"Order number " << i + 1 <<":" << endl;
			m_orders[i].getOrder();
		}
		for (int i = 0; i < m_noOfOrders; i++)
		{
			m_totalPrice += m_orders[i].m_Price;
		}
		tax = m_totalPrice * 0.13;
		m_totalPriceWithTax = m_totalPrice + tax;
	}

	

	void Vendor::displayOrders()
	{
		cout << endl;
		cout << "********** Order Summary **********" << endl;
		for (int i = 0; i < m_noOfOrders; i++)
		{
            if (i == m_noOfOrders - 1)
            {
                cout << endl;
            }
			cout << "Order No: " << i + 1 << ":" << endl;
			m_orders[i].printOrder();
		}
        cout << "-----------------------------------" << endl;
        cout.setf(ios::left);
        cout.width(6);
        cout << "Price:";
        cout.unsetf(ios::left);
        cout.width(29);
        cout << m_totalPrice << endl;
        
        cout.setf(ios::left);
        cout.width(4);
        cout << "Tax:";
        cout.unsetf(ios::left);
        cout.width(31);
        cout << tax << endl;
        
        cout.setf(ios::left);
        cout.width(16);
        cout << "Total Price ($):";
        cout.unsetf(ios::left);
        cout.width(19);
        cout << m_totalPriceWithTax << endl;
		
	}
	void Vendor::clearData()
	{
		deallocate();
	}
	
	



}
