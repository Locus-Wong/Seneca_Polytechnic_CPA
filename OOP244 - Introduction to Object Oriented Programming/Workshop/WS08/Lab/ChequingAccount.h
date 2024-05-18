//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 20 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.h
// Version 1.0
// Date:
// Author: 
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H
#include <iostream>
#include "Account.h"
namespace seneca
{
	class ChequingAccount : public Account
	{
		double m_transactionFee{};
		double m_monthlyFee{};

	public:
		ChequingAccount(double balance, double transaction_Fee, double monthEnd_Fee); // transaction_Fee = 0.50, monthEnd_Fee = 2.00
		bool credit(double transactionFee);
		bool debit(double transactionFee);
		void monthEnd();
		void display(std::ostream& ostr) const;
		~ChequingAccount();
	};
}
#endif
