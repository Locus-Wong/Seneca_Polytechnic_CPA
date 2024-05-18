/***********************************************************************
// OOP244 Workshop 10 p1: tester program
//
// File: main.cpp
// Version 1.1
// Author: Jeevan Pant	
// Description: 
//
// Revision History
// -----------------------------------------------------------
// Name           Version           Reason
// Fardad           1.1             Simplified the scope for lab
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Module to be completed by students
#include <iostream>
#include <iomanip>
#include "Book.h"
#include "Student.h"
#include "MatchPair.h"

using namespace seneca;
using namespace std;

int main()
{
	const int size1 = 9;
	const int size2 = 8;
	int size3;
	int x[] = { 288, 1001, 322, 554, 3, 66, 758, 2022, 70 };
	double y[] = { 1.999, 26.96, 3.00, 103.72, 59.9, 88.8, 37.95, 322.00 };
	Book bks[] = { Book("C Programming Langauge",288,26.96,"BSABSDCPACPP",4),
		Book("Learn Python Programming",554,59.99,"BTMDSADAD",3),
		Book("Pat Recog and Mach Learn",758,103.72,"DSABSA",2),
		Book("Mach Learn in Business",287,37.95,"BTMBSD",2)
	};
	float marks[][32] = { {56.6f,62.2f,71.2f},{59.9f,80.1f},{88.8f},{80.1f,70.2f,66.6f},
		{58.8f,64.4f},{81.1f,76.6f,72.2f},{50.0f,61.1f,70.9f,81.1f}
	};
	Student stds[] = { Student(1001,"Beans Yanson","BSD",marks[0],3),
		Student(1005,"Archie Mollen","BSA",marks[1],2),
		Student(1026,"Mugsy Brown","CPA",marks[2],1),
		Student(2022,"Sally Sparrow","CPP",marks[3],3),
		Student(2033,"Maulin Codi","BTM",marks[4],2),
		Student(1055,"John Bolton","DSA",marks[5],3),
		Student(2130,"Joe Jackson","DAD",marks[6],4)
	};
	
	cout << "====================================================================\n";
	cout << "|| Match tester for int and double arrays (double matched to int) ||\n";
	cout << "+------------+---------------+--------------------------------------\n";
	cout << "| int value  | double value  |\n";
	cout << "+ ---------- + ------------- +\n";
	Pair<int,double>* ret1 = matches(x, y, size1, size2, size3); // TODO-1a: call matches function for arrays x and y, pass size3 as 5th argument; 
																							     // copy returned address to a pointer called ret1 (of type Pair specialized for int and double)
	for (int i = 0; i < size3; i++)
	{
		cout << "|    " << setw(6) << ret1[i].first << " <-> " 
			<< setw(6) << fixed << setprecision(2) << ret1[i].second << "       |" << endl;
	}
	releaseMem(ret1); // TODO-1b: call ReleaseMem function to release dynamic array ret1

	cout << "+------------+---------------+\n";
	cout << endl;
	cout << "===========================================================================\n";
	cout << "|| Match tester for Book and int arrays (int matched to number of pages) ||\n";
	cout << "+--------------------------------------------------------------+------------+\n";
	cout << "|                            Book                              |  int value |\n";
	cout << "+ ------------------------------------------------------------ + ---------- +\n";
	Pair<Book, int>* ret2 = matches(bks,x, 4, size1, size3); /// TODO-2a: call matches function for arrays bks and x, pass size3 as 5th argument;
																								 // copy returned address to a pointer called ret2 (of type Pair specialized for Book and int)
	for (int i = 0; i < size3; i++)
	{
		cout << "| " << setw(70) << ret2[i].first << " <-> " 
			<< ret2[i].second << "       |" << endl;
	}
	releaseMem(ret2); // TODO-2b: call ReleaseMem function to release dynamic array ret2
	cout << "+--------------------------------------------------------------+------------+\n";
	cout << endl;
	cout << "============================================================================\n";
	cout << "|| Match tester for Book and double arrays (double matched to book price) ||\n";
	cout << "+--------------------------------------------------------------+---------------+\n";
	cout << "|                             Book                             |  double value |\n";
	cout << "+ ------------------------------------------------------------ + ------------- +\n";
	Pair<Book,double>* ret3 = matches(bks, y, 4, size2, size3); /// TODO-3a: call matches function for arrays bks and y, pass size3 as 5th argument;
																								 // copy returned address to a pointer called ret3 (of type Pair specialized for Book and double)
	for (int i = 0; i < size3; i++)
	{
		cout << "| " << ret3[i].first << " <-> " 
			<< setw(6) << fixed << setprecision(2) << ret3[i].second << "       |" << endl;
	}
	releaseMem(ret3); // TODO-3b: call ReleaseMem function to release dynamic array ret3 
	cout << "+--------------------------------------------------------------+---------------+\n";
	cout << endl;
	cout << "==========================================================================\n";
	cout << "|| Match tester for Student and int arrays (int matched to student id)  ||\n";
	cout << "+--------------------------------------------------+---------------+------\n";
	cout << "|                     Student                      |  int value    |\n";
	cout << "+ ------------------------------------------------ + ------------- +\n";
	Pair<Student, int>* ret4 = matches(stds, x, 7, size1, size3); /// TODO-4a: call matches function for arrays stds and x, pass size3 as 5th argument;
																								 // copy returned address to a pointer called ret4 (of type Pair specialized for Student and int)
	for (int i = 0; i < size3; i++)
	{
		cout << "| " << ret4[i].first << " <-> " << ret4[i].second << "         |" << endl;
	}
	releaseMem(ret4); // TODO-4b: call ReleaseMem function to release dynamic array ret4
	cout << "+--------------------------------------------------+---------------+\n";
	cout << endl;
	cout << "===================================================================================\n";
	cout << "|| Match tester for Student and double arrays (double matched to average marks)  ||\n";
	cout << "+--------------------------------------------------+---------------+---------------\n";
	cout << "|                      Student                     |  Double value |\n";
	cout << "+ ------------------------------------------------ + ------------- +\n";
	Pair<Student,double>* ret5 = matches(stds, y, 7, size2, size3); /// TODO-5a: call matches function for arrays stds and y, pass size3 as 5th argument;
																								 // copy returned address to a pointer called ret5 (of type Pair specialized for Student and double)
	for (int i = 0; i < size3; i++)
	{
		cout << "| " << ret5[i].first << " <-> " << ret5[i].second << "        |" << endl;
	}
	releaseMem(ret5); // TODO-5b: call ReleaseMem function to release dynamic array ret5
	cout << "+--------------------------------------------------+---------------+\n";
	cout << endl;
	cout << "===========================================================================================================\n";
	cout << "|| Match tester for Student and Book arrays (student program matched to programs in which book is used)  ||\n";
	cout << "+--------------------------------------------------+-----------------------------------------";
	cout << "---------------------+\n";
	cout << "|                       Student                    |  ";
	cout << "                         Book                               |\n";
	cout << "+ ------------------------------------------------ + ";
	cout << "------------------------------------------------------------ +\n";
	Pair<Student,Book>* ret6 = matches(stds, bks, 7, 4, size3); /// TODO-6a: call matches function for arrays stds and bks, pass size3 as 5th argument;
																								 // copy returned address to a pointer called ret6 (of type Pair specialized for Student and Book)
	for (int i = 0; i < size3; i++)
	{
		cout << "| " << ret6[i].first << " <-> " << ret6[i].second << " |" << endl;
	}
	releaseMem<Pair<Student,Book>>(ret6); // TODO-6b: call ReleaseMem function to release dynamic array ret6
	cout << "+--------------------------------------------------+-----------------------------------------";
	cout << "---------------------+\n";

	return 0;
}

