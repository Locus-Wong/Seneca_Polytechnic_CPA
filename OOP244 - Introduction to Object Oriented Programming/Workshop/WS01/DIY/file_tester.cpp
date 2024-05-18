//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 19 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "file.h"

using namespace std;
using namespace seneca;
int main() {
   StMark m[MAX_NO_RECS];
   int recoredsRead = 0;
   if (openFile("group.csv")) {
      cout << "This should not happen!" << endl;
   }
   if (openFile("group1.csv")) {
      recoredsRead = readMarks(m);
      cout << "GROUP1: ....................." << endl;
      for (int i = 0; i < recoredsRead; i++) {
         cout << (i + 1) << ": " << m[i].name << " " << m[i].surname << " [" << m[i].mark << "]" << endl;
      }
      closeFile();
   }
   else{
      cout << "This should not happen!" << endl;
   }
   if (openFile("group2.csv")) {
      cout << "GROUP2: ....................." << endl;
      recoredsRead = readMarks(m);
      for (int i = 0; i < recoredsRead; i++) {
         cout << (i + 1) << ": " << m[i].name << " " << m[i].surname << " [" << m[i].mark << "]" << endl;
      }
      closeFile();
   }
   else {
      cout << "This should not happen!" << endl;
   }
return 0;
}


