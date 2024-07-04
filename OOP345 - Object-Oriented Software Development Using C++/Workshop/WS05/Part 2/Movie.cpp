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
#include <string>
#include "Movie.h"
namespace seneca {
	std::string trimMovie(const std::string& str)
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

	const std::string& Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		size_t pos1 = 0;
		size_t pos2 = strMovie.find(',');
		m_title = trimMovie(strMovie.substr(pos1, pos2));
		pos1 = pos2 + 1;
		pos2 = strMovie.find(',', pos1);
		m_releaseYear = std::stoi(trimMovie(strMovie.substr(pos1, pos2 - pos1)));
		pos1 = pos2 + 1;
		m_desc = trimMovie(strMovie.substr(pos1));
	}

	std::ostream& operator<<(std::ostream& ostr, const Movie& movie)
	{
		ostr << std::setw(40) << std::right << movie.m_title << " | "
			<< std::setw(4) << std::right << movie.m_releaseYear << " | "
			<< std::left << movie.m_desc << '\n';
		return ostr;
	}

}