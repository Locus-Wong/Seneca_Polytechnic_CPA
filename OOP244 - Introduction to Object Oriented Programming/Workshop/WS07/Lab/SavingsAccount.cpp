//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 17 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "SavingsAccount.h"
#include <iostream>
#include "BankAccount.h"
using namespace std;
namespace seneca
{
	void SavingsAccount::writeInterest(std::ostream& out) const
	{
		out.precision(3);
		out.setf(ios::fixed);
		out << m_interest;
		out << "%";
		out.unsetf(ios::fixed);
	}

	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) : BankAccount(name, openDate, depInfo, balance)
	{
		m_interest = interest;
		m_interestDate = interestDate;
	}

	void SavingsAccount::applyInterest(Date& dt)
	{
		double balance = BankAccount::getBalance(); // get the current balance
		double interest = balance * m_interest; // calculate the interest
		double newBalance = balance + interest; // calculate the new balance
		cout << "   ";
		BankAccount::writeCurrency(cout, balance);
		cout << " + ";
		BankAccount::writeCurrency(cout, interest);
		cout << " (";
		writeInterest(cout);
		cout << ")";
		cout << " = ";
		BankAccount::setBalance(newBalance); // set the new balance
		BankAccount::writeCurrency(cout, newBalance); 
		cout << " | " << m_interestDate << " => ";
		m_interestDate = dt;
		cout << m_interestDate << endl;
	}

	std::ostream& SavingsAccount::write(std::ostream& out) const
	{
		BankAccount::write(out);
		out << " | ";
		writeInterest(out);
		out << " | " << m_interestDate;
		return out;
	}

	std::istream& SavingsAccount::read(std::istream& in)
	{
		BankAccount::read(in);
		cout << "Interest Date ";
		in >> m_interestDate;
		cout << "Interest Rate: ";
		in >> m_interest;
		in.ignore(1000, '\n');
		return in;
	}

	std::istream& operator>>(std::istream& in, SavingsAccount& acct)
	{
		return acct.read(in);
	}

	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct)
	{
		return acct.write(out);
	}
}
