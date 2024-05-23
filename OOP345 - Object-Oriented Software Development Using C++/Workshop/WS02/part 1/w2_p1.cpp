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
#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include "ProteinDatabase.h"
#include "ProteinDatabase.h" // intentional
#include "TimedTask.h"
#include "TimedTask.h" // intentional

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; ++i)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc == 1)
	{
		std::cerr << "ERROR: Missing file name!\n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cerr << "ERROR: Too many arguments!\n";
		return 2;
	}

	seneca::TimedTask t;
	{
		t.startClock();
		seneca::ProteinDatabase protein_DBA;
		t.stopClock();
		t.addTask("  0-arg Constructor");
		std::cout << "  0-arg Constructor - a.size = "
			<< std::setw(7) << protein_DBA.size() << " strings -> ";
		std::cout << std::setw(20) << "(a) String     1: [" << protein_DBA[  0] << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << protein_DBA[ 99] << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << protein_DBA[999] << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << protein_DBA[protein_DBA.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << protein_DBA[protein_DBA.size()] << "]\n\n";


		t.startClock();
		seneca::ProteinDatabase protein_DBB(argv[1]);
		t.stopClock();
		t.addTask("  1-arg Constructor");
		std::cout << "  1-arg Constructor - b.size = "
			<< std::setw(7) << protein_DBB.size() << " strings -> ";
		std::cout << std::setw(20) << "(b) String     1: [" << protein_DBB[  0].substr(0,20) << "]\n";
		std::cout << std::setw(70) << "(b) String   100: [" << protein_DBB[ 99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(b) String  1000: [" << protein_DBB[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(b) String  last: [" << protein_DBB[protein_DBB.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(b) String last+: [" << protein_DBB[protein_DBB.size()] << "]\n\n";


		t.startClock();
		seneca::ProteinDatabase protein_DBC{ protein_DBB };
		t.stopClock();
		t.addTask("  Copy Constructor");
		std::cout << "  Copy Constructor  - c.size = "
			<< std::setw(7) << protein_DBC.size() << " strings -> ";
		std::cout << std::setw(20) << "(c) String     1: [" << protein_DBC[0].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String   100: [" << protein_DBC[99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String  1000: [" << protein_DBC[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String  last: [" << protein_DBC[protein_DBC.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String last+: [" << protein_DBC[protein_DBC.size()] << "]\n\n";


		t.startClock();
		protein_DBA = protein_DBB;
		t.stopClock();
		t.addTask("  Copy Assignment");
		std::cout << "  Copy Assignment   - a.size = "
			<< std::setw(7) << protein_DBA.size() << " strings -> ";
		std::cout << std::setw(20) << "(a) String     1: [" << protein_DBA[0].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << protein_DBA[99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << protein_DBA[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << protein_DBA[protein_DBA.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << protein_DBA[protein_DBA.size()] << "]\n\n";


		t.startClock();
	}
	t.stopClock();
	t.addTask("  Destructor");

	std::cout << t;

	return cout;
}
