/***********************************************************************
// OOP244 Project ms4
//
// File  TrgP_Tester.cpp
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
#include "TriagePatient.h"
#include "Utils.h"
using namespace std;
using namespace seneca;
int main() {
   ifstream input("input.txt");
   U.setDebugTime(12, 34);
   TriagePatient A, B;
   cout << "Testing TriagePatient:" << endl;
   cout << "Enter the following values when prompted:" << endl
      << "aaa" << endl
      << "123123123" << endl
      << "aaa aaa aaa" << endl
      << "------------------------" << endl << endl;
   A.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   cin >> A;
   cout << endl << "Enter the following values when prompted:" << endl
      << "bbb" << endl
      << "234234234" << endl
      << "bbb bbb bbb" << endl
      << "------------------------" << endl << endl;
   B.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   cin >> B;
   cout << endl << "Patients information entered:" << endl;
   cout << A << endl << B << endl;
   cout << "CSV output: " << endl;
   cerr << A << endl << B << endl << endl;
   cout << "Linear output:" << endl;
   clog << A << endl << B << endl << endl;
   cout << "Testing CSV input;" << endl
      << "   Reading \"ccc,333333333,10,23:45,ccc ccc ccc\" from input.txt." << endl;
   input.ignore(1000, '\n');
   input >> A;
   input.ignore(1000, '\n');
   cout << endl << "Data read:" << endl;
   cout << A << endl;
   U.setDebugTime(23, 55);
   cout << "Testing global ticket number variable:" << endl
      << "Enter the following values when prompted:" << endl
      << "ddd" << endl
      << "444444444" << endl
      << "ddd ddd ddd" << endl
      << "------------------------" << endl << endl;
   TriagePatient C;
   C.setArrivalTime();
   cin >> C;
   cout << endl << "Patient information entered:" << endl;
   cout << C << endl;
   return 0;
}

/*output
Testing TriagePatient:
Enter the following values when prompted:
aaa
123123123
aaa aaa aaa
------------------------

Enter Patient information:
Name: aaa
OHIP: 123123123
Symptoms: aaa aaa aaa

Enter the following values when prompted:
bbb
234234234
bbb bbb bbb
------------------------

Enter Patient information:
Name: bbb
OHIP: 234234234
Symptoms: bbb bbb bbb

Patients information entered:
TRIAGE
Ticket No: 1, Issued at: 12:34
aaa, OHIP: 123123123
Symptoms: aaa aaa aaa

TRIAGE
Ticket No: 2, Issued at: 12:37
bbb, OHIP: 234234234
Symptoms: bbb bbb bbb

CSV output:
T,aaa,123123123,1,12:34,aaa aaa aaa
T,bbb,234234234,2,12:37,bbb bbb bbb

Linear output:
aaa..................................................123123123    1 12:34
bbb..................................................234234234    2 12:37

Testing CSV input;
   Reading "ccc,333333333,10,23:45,ccc ccc ccc" from input.txt.

Data read:
TRIAGE
Ticket No: 10, Issued at: 23:45
ccc, OHIP: 333333333
Symptoms: ccc ccc ccc

Testing global ticket number variable:
Enter the following values when prompted:
ddd
444444444
ddd ddd ddd
------------------------

Name: ddd
OHIP: 444444444
Symptoms: ddd ddd ddd

Patient information entered:
TRIAGE
Ticket No: 11, Issued at: 23:55
ddd, OHIP: 444444444
Symptoms: ddd ddd ddd
*/