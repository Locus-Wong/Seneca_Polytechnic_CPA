//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 29 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Assessment.h"
namespace seneca
{
    bool read(int& value, FILE* fptr)
    {
        if (fptr != nullptr)
        {
            if (fscanf(fptr, "%d", &value) == 1)
            {
                return true;
            }
        }
        return false;
    }

    bool read(double& value, FILE* fptr)
    {
        if (fptr != nullptr)
        {
            if (fscanf(fptr, "%lf", &value) == 1)
            {
                return true;
            }
        }
        return false;
    }

    bool read(char* cstr, FILE* fptr)
    {
        if (fptr != nullptr)
        {
            if (fscanf(fptr, ",%60[^\n]\n", cstr) == 1)
            {
                return true;
            }
        }
        return false;

    }

    bool read(Assessment& assess, FILE* fptr)
    {
        double tempMark;
        char tempTitle[61] = { 0 };
        if (fptr != nullptr)
        {
            if (fscanf(fptr, "%lf,%60[^\n]\n", &tempMark, tempTitle) == 2)
            {
                size_t len = strlen(tempTitle); // get the length of the cString
                assess.m_mark = new double; // allocate dynamic double
               assess.m_title = new char[len + 1];  // allocate dynamic cString
                *assess.m_mark = tempMark;  // copy the value of tempMark to the dynamic double
                strcpy(assess.m_title, tempTitle); // copy the value of tempTitle to the dynamic cString

              return true;
            }
        }

        return false;
    }

    void freeMem(Assessment*& aptr, int size)
    {
        // Check if the pointer is not null
        if (aptr)
        {
            // Loop through each element of the dynamic array
            for (int i = 0; i < size; i++)
            {
                // Delete the dynamic double and dynamic cString
                delete aptr[i].m_mark;
                delete[] aptr[i].m_title;
            }

            // Delete the dynamic array itself
            delete[] aptr;

            // Set the pointer to null after deletion
            aptr = nullptr;
        }
    }

    int read(Assessment*& aptr, FILE* fptr) // pass a pointer to an Assessment object 
    {
        int numRecords = 0;
        int readCount = 0;

        if (read(numRecords, fptr) == false)
        {
            return 0;
        }
       
        // Allocate dynamic array of Assessments
        aptr = new Assessment[numRecords + 1];


        if (read(*aptr, fptr) == false) // store the first row of data in the dynamic array
        {
            seneca::freeMem(aptr, readCount);
            return 0;
        }
        else
        {
            readCount = 1;
            for(int i = 1; read(aptr[i], fptr) == true; i++) // store the second row of data in the dynamic array
            {
				readCount++;
            }
        } 

        if (readCount != numRecords)
        {
            seneca::freeMem(aptr, readCount);
            return 0;
        }
        return numRecords;
    }

}