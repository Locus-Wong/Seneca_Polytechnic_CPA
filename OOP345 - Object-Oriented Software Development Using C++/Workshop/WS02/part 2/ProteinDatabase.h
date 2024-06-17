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
#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H
#include <string>
namespace seneca
{
	class ProteinDatabase
	{
		std::string* m_proteinSequences{};
		size_t m_noOfProteins{};
	public:
		ProteinDatabase(); // 0-arg constructor
		ProteinDatabase(const std::string& filename); // 1-arg constructor
		ProteinDatabase(const ProteinDatabase& src); // copy constructor
		ProteinDatabase& operator=(const ProteinDatabase& src); // copy assignment operator
		size_t size() const; // a query that returns the number of protein sequences stored in the current object.
		std::string operator[](size_t index) const;// a query that returns a copy of the protein sequence at the index received as the function parameter.
        ProteinDatabase(ProteinDatabase&& src); // move constructor
        ProteinDatabase& operator=( ProteinDatabase&& src); // move assignment
		~ProteinDatabase();
	};
}
#endif
