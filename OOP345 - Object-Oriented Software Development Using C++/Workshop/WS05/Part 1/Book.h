/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 13 June 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include <string>
namespace seneca {

	class Book
	{
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		std::string m_desc{};
		double m_price{};
		size_t m_year{};

	public:
		Book() = default;
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price(); // modifier
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
		friend std::string trimBook(const std::string& str); // custom trim function
		
		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			// As spellChecker is a function object, it can be called like a function.
			spellChecker(m_desc); // current Book's description is passed to the function object
		}
	};
}
#endif