/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 23 May 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#include <fstream>
#include <string>
#include "ProteinDatabase.h"
using namespace std;
namespace seneca
{
	ProteinDatabase::ProteinDatabase()
	{
		m_proteinSequences = nullptr;
		m_noOfProteins = 0;
	}

	ProteinDatabase::ProteinDatabase(const std::string& filename) : m_proteinSequences{ nullptr }, m_noOfProteins{ 0 }
	{
		ifstream file(filename);
		std::string readLine;
		while (getline(file, readLine))
		{
			if (readLine[0] == '>')
			{
				m_noOfProteins++;
			}
		}
        file.clear();
		readLine = "";
		m_proteinSequences = new string[m_noOfProteins];
        file.seekg(std::ios::beg);
		int i = 0;
        
		while (getline(file, readLine))
		{
			if (readLine[0] == '>')
			{
				i++;
			}
			else 
			{
				m_proteinSequences[i - 1] += readLine;
			}	
		}
		file.close();

	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src)
	{
		operator=(src);
	}

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src)
	{
		if (this != &src)
		{
			delete[] m_proteinSequences;
			m_proteinSequences = new string[src.m_noOfProteins];
			m_noOfProteins = src.m_noOfProteins;
			for (size_t i = 0; i < m_noOfProteins; i++)
			{
				m_proteinSequences[i] = src.m_proteinSequences[i];
			}
		}

		return *this;
	}

	size_t ProteinDatabase::size() const
	{
		return m_noOfProteins;
	}

	std::string ProteinDatabase::operator[](size_t index) const
	{
		return (m_proteinSequences) ? (index > (m_noOfProteins - 1) ? "" : m_proteinSequences[index]) : ""; // if m_proteinSequences is nullptr, return empty string
																											// if index is greater than the number of proteins, return empty string
	}

	ProteinDatabase::~ProteinDatabase()
	{
		delete[] m_proteinSequences;
		m_proteinSequences = nullptr;
	}

}
