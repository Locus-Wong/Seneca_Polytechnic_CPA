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
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <iostream>
#include <string>
namespace seneca {
	class Movie
	{
		std::string m_title{};
		size_t m_releaseYear{};
		std::string m_desc{};
	public:
		Movie() = default;
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::string trimMovie(const std::string& str); // custom trim function
		friend std::ostream& operator<<(std::ostream& ostr, const Movie& movie);
		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			// As spellChecker is a function object, it can be called like a function.
			spellChecker(m_title); // current movie title is passed to the function object
			spellChecker(m_desc); // current movie description is passed to the function object
		}
	};
}
#endif