//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 29 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "LibraryItem.h"
namespace seneca 
{
	class Book : public LibraryItem
	{
		char* m_author{};
		void copy(const Book& src);
	
	public:
			Book(const char* title, int year, const char* author);
			Book (const Book& other);
			Book& operator = (const Book& other);
			virtual ~Book();
			std::ostream& display(std::ostream& ostr = std::cout)const;
			bool operator > (const Book& other)const;
	};
}
#endif
