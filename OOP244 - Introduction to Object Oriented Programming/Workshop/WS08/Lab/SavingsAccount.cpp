//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 20 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include <iostream>
#include "SavingsAccount.h"
using namespace std;
namespace seneca 
{
	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance)
	{
		if (interestRate)
		{
			m_interestRate = interestRate;
		}
	}


	void SavingsAccount::monthEnd() // calculates the interest earned on the current balance and credits the account with that interest.
	{
		if (m_interestRate)
		{
			double interest = balance() * m_interestRate;
			Account::credit(interest);
		}
	}

	void SavingsAccount::display(std::ostream& ostr) const
	{
		ostr << "Account type: Savings" << endl;
		ostr.precision(2);
		ostr.setf(ios::fixed);
		ostr << "Balance: $" << balance() << endl;
		ostr << "Interest Rate (%): " << m_interestRate * 100 << endl;
        ostr.precision(6); // set to default precision
        ostr.unsetf(ios::fixed);

	}

	SavingsAccount::~SavingsAccount()
	{
		m_interestRate = 0;
	}

}
