//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 19 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "file.h"   // file.h already include StMark.h
#include "graph.h" // graph.h already include io.h

using namespace std;
namespace seneca {

// Sort the student marks using bubble sort algorithm
    void sortStMark (StMark* marks, const int noOfRecords)
    {
        struct StMark temp;
        for (int i = 0; i < noOfRecords-1; i++)
        {
            for (int j = 0; j < noOfRecords-i-1; j++)
            {
                if (marks[j+1].mark > marks[j].mark)
                {
                    temp = marks[j+1];
                    marks[j+1] = marks[j];
                    marks[j] = temp;
                }
            }
        }
    }

// Count how many students are in each mark group
    void countOfMarkGroup (const StMark* marks, const int noOfRecords, int * Gp)
    {
        for (int i = 0; i < noOfRecords ; i++)
        {
            if (marks[i].mark >= 91 && marks[i].mark <= 100)
            {
                ++Gp[0];

            }
            else if (marks[i].mark >= 81 && marks[i].mark <= 90)
            {
                ++Gp[1];
            }
            else if (marks[i].mark >= 71 && marks[i].mark <= 80)
            {
                ++Gp[2];
            }
            else if (marks[i].mark >= 61 && marks[i].mark <= 70)
            {
                ++Gp[3];
            }
            else if (marks[i].mark >= 51 && marks[i].mark <= 60)
            {
                ++Gp[4];
            }
            else if (marks[i].mark >= 41 && marks[i].mark <= 50)
            {
                ++Gp[5];
            }
            else if (marks[i].mark >= 31 && marks[i].mark <= 40)
            {
                ++Gp[6];
            }
            else if (marks[i].mark >= 21 && marks[i].mark <= 30)
            {
                ++Gp[7];
            }
            else if (marks[i].mark >= 11 && marks[i].mark <= 20)
            {
                ++Gp[8];
            }
            else if (marks[i].mark >= 0 && marks[i].mark <= 10)
            {
                ++Gp[9];
            }
            
        }
    }

// Print student marks and their name order by their marks (DESC)
    void printMarkRanking (const struct StMark* m, const int noOfRecords)
    {
        for (int i = 0; i < noOfRecords; i++)
        {
            printInt (i + 1, 3);
            cout << ": " << "[";
            printInt(m[i].mark, 3);
            cout << "] " << m[i].name << " " << m[i].surname  << endl;
        }
    }

// Print the whole report of the study performance for all students
    bool printReport(const char* filename)
  {
        StMark m[MAX_NO_RECS]{};  // struct array with all elements of the array are zero-initialized
        int recoredsRead = 0;
        int Gp[10]{};
        int max = 0;
        if(openFile(filename))
        {
            recoredsRead = readMarks(m);    //return cnt (number of records read)
            
            sortStMark(m, recoredsRead);
            
            countOfMarkGroup (m, recoredsRead, Gp);
            
            max = findMax(Gp); // find the value of max, so that we can know that do we need to scale our graph
            
            // UPPER PART
            labelLine(GRAPH_WIDTH, "Students' mark distribution"); // print the +---Students' mark distribution---+ line
            
            printGraph(Gp, max); // print the statistics of student marks
            
            line(GRAPH_WIDTH); // print the +-----+ line with GRAPH_WIDTH length
            
            // LOWER PART
            printMarkRanking(m, recoredsRead); // print the mark rankings of students
           
            printHiddenLine(40); // print the most bottom hidden line
            
            closeFile();
        }
        else
        {
            return false;
        }
        
        return true;
    }
    
    

}
