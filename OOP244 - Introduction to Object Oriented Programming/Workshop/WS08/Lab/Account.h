//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 20 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.h
// Version 1.0
// Date:
// Author: 
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include "iAccount.h"
namespace seneca 
{
	class Account : public iAccount // abstract base class
	{
		double m_balance{}; // {}: if no amount is specified, the default balance is 0
	public:
		Account(double balance); 
		bool credit(double amount);
		bool debit(double amount);
		virtual void monthEnd() = 0; // applies month-end transactions to the account
		virtual void display(std::ostream& ostr) const = 0; 
		virtual ~Account();
	protected:
		double balance() const;

	};

}
#endif
