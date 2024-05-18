/***********************************************************************
// OOP244 Project ms4
//
// File  TstP_Tester.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include <fstream>
#include "Patient.h"
#include "TestPatient.h"
#include "utils.h"
using namespace std;
using namespace seneca;
int main() {
   ifstream input("input.txt");
   U.setDebugTime(12, 34);
   TestPatient A, B;
   cout << "Testing TestPatient:" << endl
      << "Enter the following values when prompted:" << endl
      << "aaa" << endl
      << "123123123" << endl
      << "------------------------" << endl << endl;
   A.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   cin >> A;
   cout << endl << "Enter the following values when prompted:" << endl
      << "bbb" << endl
      << "234234234" << endl
      << "------------------------" << endl << endl;
   B.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   cin >> B;
   cout << endl << "Patients information entered:" << endl;
   cout << A << endl << B << endl;
   cout << "CSV output:" << endl;
   cerr << A << endl << B << endl << endl;
   cout << "Linear output:" << endl;
   clog << A << endl << B << endl << endl;
   cout << "Testing CSV input;" << endl
      << "   Reading \"ccc,333333333,10,23:45\" from input.txt." << endl;
   input >> A;
   input.ignore(100, '\n');
   cout << endl << "Data read:" << endl;
   cout << A << endl;
   U.setDebugTime(23, 55);
   cout << "Testing global ticket number variable:" << endl
      << "Enter the following values when prompted:" << endl
      << "ddd" << endl
      << "345345345" << endl
      << "------------------------" << endl << endl;
   TestPatient C;
   C.setArrivalTime();
   cin >> C;
   cout << "Patient information entered:" << endl;
   cout << C << endl;
   return 0;
}

/* output:
Testing TestPatient:
Enter the following values when prompted:
aaa
123123123
------------------------

Enter Patient information:
Name: aaa
OHIP: 123123123

Enter the following values when prompted:
bbb
234234234
------------------------

Enter Patient information:
Name: bbb
OHIP: 234234234

Patients information entered:
Contagion TEST
Ticket No: 1, Issued at: 12:34
aaa, OHIP: 123123123

Contagion TEST
Ticket No: 2, Issued at: 12:37
bbb, OHIP: 234234234

CSV output:
C,aaa,123123123,1,12:34
C,bbb,234234234,2,12:37

Linear output:
aaa..................................................123123123    1 12:34
bbb..................................................234234234    2 12:37

Testing CSV input;
   Reading "ccc,333333333,10,23:45" from input.txt.

Data read:
Contagion TEST
Ticket No: 10, Issued at: 23:45
ccc, OHIP: 333333333

Testing global ticket number variable:
Enter the following values when prompted:
ddd
345345345
------------------------

Name: ddd
OHIP: 345345345
Patient information entered:
Contagion TEST
Ticket No: 11, Issued at: 23:55
ddd, OHIP: 345345345

*/