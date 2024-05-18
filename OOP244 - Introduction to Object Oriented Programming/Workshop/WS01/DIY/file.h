//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 19 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include <cstdio>
#include "StMark.h"

namespace seneca {
   const int MAX_NO_RECS = 1000;

   /// <summary>
   /// Tries to open the student records file using the file name.
   /// </summary>
   /// <param name="fname">, name of the file</param>
   /// <returns>ture if file is opened successfuly or false if not</returns>
   bool openFile(const char* fname);

   /// <summary>
   /// closes the student records file.
   /// </summary>
   void closeFile();

   /// <summary>
   /// Read one student record frome the opened student records file
   /// </summary>
   /// <param name="mark">, points to one StMark structure</param>
   /// <returns>true if the record is read successfuly</returns>
   bool readMark(StMark* mark);

   /// <summary>
   /// fills an array of StMark array with the records read from the opened student records file up to MAX_NO_RECS constant integer value.
   /// </summary>
   /// <param name="marks">, array of student marks</param>
   /// <returns>the actual number of records read.</returns>
   int readMarks(StMark* marks);
}

#endif // !SENECA_FILE_H
