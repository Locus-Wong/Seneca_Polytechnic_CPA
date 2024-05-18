//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 20 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: iAccount.h
// Version 1.0
// Date:
// Author: 
// Description
// This file defines the iAccount interface
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef IACCOUNT_H
#define IACCOUNT_H
#include <iostream>
namespace seneca
{
	class iAccount // interface
	{
	public: // pure (= 0) virtual public member functions
		virtual bool credit(double amount) = 0; // adds a positive amount to the account balance
		virtual bool debit(double amount) = 0; // subtracts a positive amount from the account balance
		virtual void monthEnd() = 0; // applies month-end transactions to the account
		virtual void display(std::ostream& ostr) const = 0; // inserts account information into an ostream object
		
		virtual ~iAccount() {}; // public empty ({}) virtual destructor
	};

	iAccount* CreateAccount(const char* str, double balance); // global helper function
}
#endif
