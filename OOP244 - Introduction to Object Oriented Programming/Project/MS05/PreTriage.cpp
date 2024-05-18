/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Citation and Sources...
 Final Project Milestone 5
 Module: PreTriage
 Filename: PreTriage.cpp
 Version 1.0
 Author   Tsz Wa Wong
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2024/4/01  Preliminary release
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "Menu.h"
#include "Patient.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Utils.h"
using namespace std;
namespace seneca
{
	Time PreTriage::getWaitTime(const Patient& P) const
	{
		int noOfSpecificPatients = 0;
		char receivedPatientType = P.type();
		for(int i = 0; i < m_noOfPatients; i++)
		{
			if (m_lineup[i]->type() == receivedPatientType)
			{
				noOfSpecificPatients++;
			}
		}
		return (receivedPatientType == 'C') ? m_averageWait_C * noOfSpecificPatients : m_averageWait_T * noOfSpecificPatients;
	}

	void PreTriage::setAverageWaitTime(const Patient& admitPatient)
	{
		int currentTime = U.getTime();
		int patientTicketTime = admitPatient.time();
		int patientTicketNumber = admitPatient.number();
		if (admitPatient.type() == 'C')
		{
			m_averageWait_C = ((currentTime - patientTicketTime) + (m_averageWait_C * (patientTicketNumber - 1))) / patientTicketNumber;
		}
		else if (admitPatient.type() == 'T')
		{
			m_averageWait_T = ((currentTime - patientTicketTime) + (m_averageWait_T * (patientTicketNumber - 1))) / patientTicketNumber;
		}

	}

	PreTriage::~PreTriage()
	{
		for (int i = 0; i < m_noOfPatients; i++)
		{
			delete m_lineup[i];
		}
		delete[] m_fileName;
	}

	void PreTriage::admit(void)
	{
		
		Menu subMenu("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
		int selection;
		int indexOfFirstPatient;
		subMenu >> selection;
        cout << endl;
		switch (selection)
		{
			case 1:
				if (indexOfFirstInLine('C') != -1)
				{
					indexOfFirstPatient = indexOfFirstInLine('C');
					cout << "******************************************" << endl;
					cout << "Call time: ";
					cout << "[";
					m_lineup[indexOfFirstPatient]->time().reset().displayMethod();
					cout << "]" << endl;
					cout << "Calling at for ";
					m_lineup[indexOfFirstPatient]->write(cout);
					cout << "******************************************" << endl << endl;
					setAverageWaitTime(*m_lineup[indexOfFirstPatient]);
					U.removeDynamicElement(m_lineup, indexOfFirstPatient, m_noOfPatients);
				}
				else
				{
					cout << "Lineup is empty!" << endl;
				}
				break;
				
			case 2:
				if (indexOfFirstInLine('T') != -1)
				{
					indexOfFirstPatient = indexOfFirstInLine('T');
					cout << "******************************************" << endl;
					cout << "Call time: ";
					cout << "[";
					m_lineup[indexOfFirstPatient]->time().reset().displayMethod();
					cout << "]" << endl;
					cout << "Calling at for ";
					m_lineup[indexOfFirstPatient]->write(cout);
					cout << "******************************************" << endl << endl;
					setAverageWaitTime(*m_lineup[indexOfFirstPatient]);
					U.removeDynamicElement(m_lineup, indexOfFirstPatient, m_noOfPatients);
				}
				else
				{
					cout << "Lineup is empty!" << endl;
				}
				break;
				
		}
	}

	int PreTriage::indexOfFirstInLine(char patientType) const
	{
		int index = -1;
		for (int i = 0; i < m_noOfPatients; i++)
		{
			if (m_lineup[i]->type() == patientType && index == -1)
			{
				index = i;
			}
		}
		return index;
	}


	PreTriage::PreTriage(const char* fileName)
	{
		 m_averageWait_C = Time(15);
		 m_averageWait_T = Time(5);
		 m_noOfPatients = 0;
		 m_fileName = new char[strlen(fileName) + 1];
		 strcpy(m_fileName, fileName); // stored in the data filename attribute for load and save purposes
		 PreTriage::load();
	}

	void PreTriage::reg()
	{
		if (m_noOfPatients == maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			Menu subMenu("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
			int selection;
			subMenu >> selection;
			switch (selection)
			{
			case 1:
				m_lineup[m_noOfPatients] = new TestPatient();
				m_lineup[m_noOfPatients]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_noOfPatients]->read(cin);
				cout << endl;
				cout << "******************************************" << endl;
				m_lineup[m_noOfPatients]->write(cout);
				cout << "Estimated Wait Time: ";
				cout << PreTriage::getWaitTime(*m_lineup[m_noOfPatients]) << endl;
				cout << "******************************************" << endl << endl;
				m_noOfPatients++;
				break;

			case 2:
				m_lineup[m_noOfPatients] = new TriagePatient();
				m_lineup[m_noOfPatients]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_noOfPatients]->read(cin);
				cout << endl;
				cout << "******************************************" << endl;
				m_lineup[m_noOfPatients]->write(cout);
				cout << "Estimated Wait Time: ";
				cout << PreTriage::getWaitTime(*m_lineup[m_noOfPatients]) << endl;
				cout << "******************************************" << endl << endl;
				m_noOfPatients++;
				break;
			}
		}
		
	}
	
	 void PreTriage::load()
	{
		cout << "Loading data..." << endl;
		int emptyFile = 0;
		Patient* localPatient = nullptr;
		ifstream input(m_fileName);
		if (input.is_open())
		{	
			char buf[1001]{};
			if (m_averageWait_C.readMethod(input))
			{
				input.ignore();
				m_averageWait_T.readMethod(input);
				input.ignore();
				for (int i = 0; i < maxNoOfPatients; i++)
				{
					input.getline(buf, 1000, ',');
					if (buf[0] == '\0' && i == 0)
					{
						cout << "No data or bad data file!" << endl << endl; // empty file
						i = maxNoOfPatients;
						emptyFile = 1;
					}
					else
					{
						for (size_t j = 0; j < strlen(buf); j++)
						{
							if (buf[j] == 'C')
							{
								localPatient = new TestPatient();
							}
							else if (buf[j] == 'T')
							{
								localPatient = new TriagePatient();
							}
							else
							{
								localPatient = nullptr;
							}

							if (localPatient)
							{
								localPatient->read(input);
								m_lineup[i] = localPatient;
								m_noOfPatients++;
							}
						}
						
					}
				}
				if (m_noOfPatients == 100)
				{
					cout << "Warning: number of records exceeded 100" << endl;
				}
				
			}
			if (!emptyFile)
			{
				cout << m_noOfPatients << " Records imported..." << endl << endl;
			}
			input.close();
		}
		else
		{
			cout << "No data or bad data file!" << endl << endl; // no file
		}
	}

	bool PreTriage::run(void)
	{
		Menu mainMenu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
		int selection = -1;

		while (mainMenu >> selection)
		{
			switch (selection)
			{
				case 1: 
					PreTriage::reg();
					break;

				case 2:
					PreTriage::admit();
					break;
					
				case 3:
					PreTriage::lineup();
					break;
			}
		}
		if (selection == 0)
		{
			PreTriage::save();
		}
	
		return 0;
	}

	void PreTriage::lineup(void)
	{
		Menu subMenu("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
		int selection;
		subMenu >> selection;
		cout << "Row - Patient name                                          OHIP     Tk #  Time" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		switch (selection)
		{
			case 1:
				for (int i = 0, j = 1; i < m_noOfPatients; i++)
				{
					if (m_lineup[i]->type() == 'C')
					{
                        cout << j++ << "   - " << flush; // use flush to force output to be immediately written to the console
                        m_lineup[i]->write(clog);
                        cout << endl;
					}
				}
				cout << "-------------------------------------------------------------------------------" << endl;
				break;
			
			case 2:
				for (int i = 0, j = 1; i < m_noOfPatients; i++)
				{
					if (m_lineup[i]->type() == 'T')
					{
                        cout << j++ << "   - " << flush; // use flush to force output to be immediately written to the console
						m_lineup[i]->write(clog);
						cout << endl;
					}
				}
				cout << "-------------------------------------------------------------------------------" << endl;
				break;
		}
	}
	
	void PreTriage::save(void)
	{
		int noOfT = 0;
		int noOfC = 0;
		cout << "Saving lineup..." << endl;
		ofstream output(m_fileName);
		if (output.is_open())
		{
			output << m_averageWait_C << ',' << m_averageWait_T << endl;
			for (int i = 0; i < m_noOfPatients; i++)
			{
				if (m_lineup[i])
				{
					m_lineup[i]->write(output);
					if (m_lineup[i]->type() == 'C')
					{
						noOfC++;
					}
					else if (m_lineup[i]->type() == 'T')
					{
						noOfT++;
					}
					output << endl;
				}
			}
			output.close();
		}
		cout << noOfC <<" Contagion Tests and "<< noOfT << " Triage records were saved!" <<endl;
		
	}
	
	
}
