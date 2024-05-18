//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 17 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "BankAccount.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace seneca
{
	double BankAccount::getBalance() const
	{
		return m_balance;
	}
	void BankAccount::setBalance(double balance)
	{
		if(balance)
		m_balance = balance;
	}
	void BankAccount::writeCurrency(std::ostream& out, double amount) const
	{
		out.precision(2);
		out << std::fixed;
		out << "$" << amount;
		out.unsetf(std::ios::fixed);
	}

	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
	{
		strcpy(m_name, name);
		m_openDate = openDate;
		m_depInfo = depInfo;
		m_balance = balance;
	}

	std::ostream& BankAccount::write(std::ostream& out) const
	{
        out << ">> ";
		out << m_name << " | ";
		writeCurrency(out, m_balance);
		out << " | " << m_openDate << " | " << m_depInfo;
		return out;
	}

	std::istream& BankAccount::read(std::istream& in)
	{
		cout << "Name: ";
		in.getline(m_name, 51); // holds up to 50 chars
		cout << "Opening Balance: ";
		in >> m_balance;
		cout << "Date Opened "; // the read method in class Date already print (year month day):
		in >> m_openDate; //  the write method in class Date already add - between year month day
		cout << "Transit #: ";
		in >> m_depInfo.m_transit;
		cout << "Institution #: ";
		in >> m_depInfo.m_institution;
		cout << "Account #: ";
		in >> m_depInfo.m_account;
		in.ignore(1000, '\n');
		return in;
	}

	std::istream& operator>>(std::istream& in, BankAccount& acct)
	{
		return acct.read(in);
	}

	std::ostream& operator<<(std::ostream& out, const BankAccount& acct)
	{
		return acct.write(out);
	}

}
