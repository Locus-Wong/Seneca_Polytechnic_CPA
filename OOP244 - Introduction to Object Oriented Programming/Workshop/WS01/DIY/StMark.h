//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 19 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H

namespace seneca {

   struct StMark 
  {
      char name[21];
      char surname[31];
      int mark;
  };

// Sort the student marks using bubble sort algorithm
void sortStMark (StMark* marks, const int noOfRecords);

// Count how many students are in each mark group
void countOfMarkGroup (const StMark* marks, const int noOfRecords, int * Gp);

// Print student marks and their name order by their marks (DESC)
void printMarkRanking (const struct StMark* m, const int noOfRecords);

// Print the whole report of the study performance for all students
bool printReport(const char* filename);

}


#endif // !SENECA_STMARK_H


