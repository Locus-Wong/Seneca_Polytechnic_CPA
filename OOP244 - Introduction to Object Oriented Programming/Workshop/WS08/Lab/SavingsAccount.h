//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 20 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingAccount.h
// Version 1.0
// Date:
// Author:  
// Description
// This file defines the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"
namespace seneca 
{
	class SavingsAccount : public Account
	{
		double m_interestRate{};
	public:
		SavingsAccount(double balance, double interestRate); // interestRate = 0.05
		void monthEnd(); // calculates the interest earned on the current balance and credits the account with that interest.
		void display(std::ostream& ostr) const;
		~SavingsAccount();

	};
}
#endif
