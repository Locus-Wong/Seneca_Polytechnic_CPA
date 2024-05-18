//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 16 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_IO_H
#define SENECA_IO_H
namespace seneca{

// prints the int value in width of fieldWidth
void printInt(int value, int fieldWidth);

// returns number of digits in an integer
int intDigits(int value);

// Performs a fool-proof integer entry assuming the user will only enter numeric values.
// if the user enters non digit values, the function will hang in an endless loop.
int getInt(int min, int max);

// moves the cursor backwards
void goBack(int n);

// displays the user interface menu
int menu(int noOfSamples);

// Draws a line and adds a label
void labelLine(int n, const char* label);

// Draws a line
void line(int n);

}
#endif

