//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 29 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LibraryItem.h"
using namespace std;
namespace seneca
{
	void LibraryItem::copy(const LibraryItem& src)
	{
		if (src.m_title)
		{
			m_title = new char[strlen(src.m_title) + 1];
			strcpy(m_title, src.m_title);
		}
		else
		{
			m_title = nullptr;
		}
		m_year = src.m_year;
	}

	LibraryItem::LibraryItem() :m_title(nullptr), m_year(0) {}

	LibraryItem::LibraryItem(const char* title, int year)
	{
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
		m_year = year;
	}

	LibraryItem::LibraryItem(const LibraryItem& other)
	{
		copy(other);
	}

	LibraryItem& LibraryItem::operator=(const LibraryItem& other)
	{
		if (this != &other)
		{
			delete[] m_title;
			copy(other);
		}
		return *this;
	}

	LibraryItem::~LibraryItem()
	{
		delete [] m_title;
		m_title = nullptr;
	}

	ostream& LibraryItem::display(ostream& ostr) const
	{
		ostr << "Title: " << m_title << " (" << m_year << ")";
		return ostr;
	}
}
