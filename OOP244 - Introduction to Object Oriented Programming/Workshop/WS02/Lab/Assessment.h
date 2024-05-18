//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 29 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef Assessment_h
#define Assessment_h

#include <cstdio>
namespace seneca{

    struct Assessment {
        double* m_mark ;
        char* m_title;
    };

    bool read(int& value, FILE* fptr);

    bool read(double& value, FILE* fptr);

    bool read(char* cstr, FILE* fptr);

    bool read(Assessment& assess, FILE* fptr);

    void freeMem(Assessment*& aptr, int size);

    int read(Assessment*& aptr, FILE* fptr);
}

#endif
