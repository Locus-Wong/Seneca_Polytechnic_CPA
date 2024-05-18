//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 19 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "file.h"

using namespace std;
namespace seneca {
   std::FILE* datafile = nullptr;
   bool openFile(const char* fname)
   {
      if (datafile != nullptr) closeFile();
      datafile = fopen(fname, "r");
// Return true if the file is successfully opened
      return datafile != nullptr;
   }

   void closeFile(){
// If file is successfully read, close that file
      if (datafile) {
         fclose(datafile);
// Reset the pointer to null
         datafile = nullptr;
      }
   }

   bool readMark(StMark* markRec)
   {
// using field delimiter (comma) to extract the corresponding values
      return fscanf(datafile, "%[^,],%[^,],%d\n", markRec->name, markRec->surname, &markRec->mark) == 3;
   }

   int readMarks(StMark* marks)
   {
// read student records up to 1000 times, and return how many records in total are readed
      int cnt = 0;
      for (; cnt < MAX_NO_RECS && readMark(&marks[cnt]); cnt++);
      return cnt;
   }
}
