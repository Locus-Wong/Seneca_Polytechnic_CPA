//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 20 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the ChequingAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include <iostream>
#include "ChequingAccount.h"
using namespace std;
namespace seneca
{

	ChequingAccount::ChequingAccount(double balance, double transaction_Fee, double monthEnd_Fee) : Account(balance)
	{
		if (transaction_Fee)
		{
			m_transactionFee = transaction_Fee;
		}
		
		if (monthEnd_Fee)
		{
			m_monthlyFee = monthEnd_Fee;
		}
	}

	bool ChequingAccount::credit(double transactionFee)
	{
		return Account::credit(transactionFee) ? Account::debit(m_transactionFee) : 0;
	}

	bool ChequingAccount::debit(double transactionFee)
	{
		return Account::debit(transactionFee) ? Account::debit(m_transactionFee) : 0;
	}

	void ChequingAccount::monthEnd()
	{
		if (m_monthlyFee)
		{
			Account::debit(m_monthlyFee);
		}
	}

	void ChequingAccount::display(std::ostream& ostr) const
	{
		ostr << "Account type: Chequing" << endl;
		ostr.precision(2);
		ostr.setf(ios::fixed);
		ostr << "Balance: $" << balance() << endl;
		ostr << "Per Transaction Fee: " << m_transactionFee << endl;
		ostr << "Monthly Fee: " << m_monthlyFee << endl;
        ostr.precision(6); // set to default precision
        ostr.unsetf(ios::fixed);

	}

	ChequingAccount::~ChequingAccount()
	{
		m_transactionFee = 0;
	    m_monthlyFee = 0;
	}

}
