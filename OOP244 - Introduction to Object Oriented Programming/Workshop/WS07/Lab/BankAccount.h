//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 17 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include "DepositUtility.h"
namespace seneca
{
	class BankAccount
	{
		char m_name[51]; // The name of the person that owns the account(holds up to 50 chars).
		Date m_openDate; // An instance of the Date class to hold the date the account was opened.
		DepositInfo m_depInfo; // An instance of the DepositInfo class to hold the direct deposit information.
		double m_balance; // A doubleing point number to hold the current balance of the account.
	
	protected:
		double getBalance() const; // A query method to return the current balance of the account(m_balance).
		void setBalance(double balance); // A mutator that sets the current balance of the account(m_balance).
		void writeCurrency(std::ostream& out, double amount) const; // A utility method that inserts into out a formatted dollar amount.
	
	public:
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance); // A constructor that initializes the object with the values passed as arguments.
		std::ostream& write(std::ostream& out) const; // A query method that inserts into out the content of the object.
		std::istream& read(std::istream& in);
	};
	// Helper Functions
	std::istream& operator>>(std::istream& in, BankAccount& acct);
	std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
}
#endif
