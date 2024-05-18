//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 20 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "Account.h"

namespace seneca {

	Account::Account(double balance) : m_balance(balance < 0 ? 0.0 : balance) {}
	
	bool Account::credit(double amount)
	{	
		return (amount > 0 ? m_balance += amount : 0);
	}
	bool Account::debit(double amount)
	{
		return (amount > 0 ? m_balance -= amount : 0);
	}
	
	Account::~Account()
	{
		m_balance = 0;
	}

	double Account::balance() const
	{
		return m_balance;
	}

}
