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
#include <iostream>
#include <iomanip>
#include "Book.h"
namespace seneca {

	std::string trimBook(const std::string& str)
	{
		// Find the position of the first non-space character
		auto start = str.begin();
		while (start != str.end() && std::isspace(*start))
		{
			start++;
		}
		// If the string is all spaces, return an empty string
		if (start == str.end())
		{
			return "";
		}
		// Find the position of the last non-space character
		auto end = str.end();
		do
		{
			end--;
		} while (end > start && std::isspace(*end));
		// Return the trimmed string
		return std::string(start, end + 1);
	}

	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}

	Book::Book(const std::string& strBook)
	{
		size_t pos1 = 0;
		size_t pos2 = strBook.find(',');
		m_author = trimBook(strBook.substr(pos1, pos2 - pos1));
		pos1 = pos2 + 1;
		pos2 = strBook.find(',', pos1);
		m_title = trimBook(strBook.substr(pos1, pos2 - pos1));
		pos1 = pos2 + 1;
		pos2 = strBook.find(',', pos1);
		m_country = trimBook(strBook.substr(pos1, pos2 - pos1));
		pos1 = pos2 + 1;
		pos2 = strBook.find(',', pos1);
		m_price = std::stod(trimBook(strBook.substr(pos1, pos2 - pos1)));
		pos1 = pos2 + 1;
		pos2 = strBook.find(',', pos1);
		m_year = std::stoi(trimBook(strBook.substr(pos1, pos2 - pos1)));
		pos1 = pos2 + 1;
		pos2 = strBook.find('.', pos1);
		m_desc = trimBook(strBook.substr(pos1, pos2 + 1 - pos1)); // +1 to include the period
	}

	std::ostream& operator<<(std::ostream& ostr, const Book& book)
	{
		ostr << std::setw(20) << std::right << book.m_author << " | ";
		ostr << std::setw(22) << std::right << book.m_title << " | ";
		ostr << std::setw(5) << std::right << book.m_country << " | ";
		ostr << std::setw(4) << std::right << book.m_year << " | ";
		ostr << std::setw(6) << std::right << std::fixed << std::setprecision(2) << book.m_price << " | ";
		ostr << book.m_desc << '\n';

		return ostr;
	}

}