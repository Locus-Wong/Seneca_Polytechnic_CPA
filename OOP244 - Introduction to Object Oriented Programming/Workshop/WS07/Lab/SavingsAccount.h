//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 17 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include "DepositUtility.h"
#include "BankAccount.h"
namespace seneca
{
	class SavingsAccount : public BankAccount
	{
		double m_interest; // A double number to hold the current interest rate of the account(specified as a fraction, for example, 0.05 means 5 %).
		Date m_interestDate; // An instance of the Date class to hold the date interest was last applied to the account.
		void writeInterest(std::ostream& out) const; // A query that inserts into out interest rate(m_interest) formatted

	public:
		SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
		void applyInterest(Date& dt); // A mutator that increases the account balance by the amount of interest
		std::ostream& write(std::ostream& out) const;
		std::istream& read(std::istream& in);

	};

	// Helper Functions
	std::istream& operator>>(std::istream& in, SavingsAccount& acct);
	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
}
#endif
