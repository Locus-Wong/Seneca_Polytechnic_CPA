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
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
namespace seneca
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (!file) {
		//  throws an exception of type const char*, with the message Bad file name!.
			throw "Bad file name!";
		}
		std::string readString;
		size_t index = 0;
		do
		{
			std::getline(file, readString);
			if (file) // if the previous operation failed, the "file" object is in error mode
			{
				if (readString[0] != ' ')
				{
					size_t pos1 = readString.find(' ');
					size_t pos2 = 0;
					m_badWords[index] = readString.substr(0, pos1);
					do {
						pos1 = readString.find(' ', pos1 + 1);
						if (pos1 != std::string::npos)
						{
							pos2 = pos1;
						}
					}while (pos1 != std::string::npos);
					m_goodWords[index] = readString.substr(pos2 + 1);
					index++;
				}
			}
		} while (file);
		file.close();
	}
	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6; i++)
		{
			size_t pos = 0;
			while ((pos = text.find(m_badWords[i], pos)) != std::string::npos)
			{
				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				pos += m_goodWords[i].size();
				m_replacementCounts[i]++;
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6; i++)
		{
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_replacementCounts[i] << " replacements" << std::endl;
		}
	}
}
