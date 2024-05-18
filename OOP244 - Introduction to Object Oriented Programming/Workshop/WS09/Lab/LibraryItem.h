//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 29 Mar 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <iostream>
namespace seneca
{
	class LibraryItem
	{
		char* m_title{};
		int m_year{};
		void copy(const LibraryItem& src);
		
	public:
			LibraryItem();
			LibraryItem (const char* title, int year);
			LibraryItem (const LibraryItem& other);
			LibraryItem& operator=(const LibraryItem& other);
			virtual ~LibraryItem();
			virtual std::ostream& display(std::ostream& ostr = std::cout)const;
	};
}
#endif
