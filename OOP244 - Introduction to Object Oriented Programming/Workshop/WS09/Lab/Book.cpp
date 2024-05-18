//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 29 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;
namespace seneca
{
	void Book::copy(const Book& src)
	{
		if (src.m_author)
		{
			m_author = new char[strlen(src.m_author) + 1];
			strcpy(m_author, src.m_author);
		}
		else
		{
			m_author = nullptr;
		}
	}

	Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year)
	{
		m_author = new char[strlen(author) + 1];
		strcpy(m_author, author);
	}

	Book::Book(const Book& other) : LibraryItem(other) // also manage the copying and copy-assigning of the base class too
	{
		copy(other);
	}

	Book& Book::operator=(const Book& other)
	{
		if (this != &other)
		{
			delete[] m_author;
			copy(other);
			LibraryItem::operator=(other); // also manage the copying and copy-assigning of the base class too
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] m_author;
		m_author = nullptr;
	}

	ostream& Book::display(ostream& ostr) const
	{
		LibraryItem::display(ostr);
		ostr << endl;
        ostr << "Author: " << m_author;
		return ostr;
	}

	bool Book::operator>(const Book& other) const
	{
		return (other.m_author && m_author) ? (other.m_author[0] < m_author[0]) : false;
	}

	

}
