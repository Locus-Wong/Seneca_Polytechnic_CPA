//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 7 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Some parts of the code in Utils are references to my professor's.
#ifndef UTILS_H
#define UTILS_H
namespace seneca
{
    struct Utils
    {
        int getInt(int max = 10000, int min = 1);
        bool getLine();
    };
    extern Utils ut;
}
#endif 

