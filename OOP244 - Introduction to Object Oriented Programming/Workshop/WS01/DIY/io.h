//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 19 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_IO_H
#define SENECA_IO_H

namespace seneca{

// prints the int value in width of fieldWidth
void printInt(const int value, const int fieldWidth);

// returns number of digits in an integer
int intDigits(int value);

// moves the cursor backwards
void goBack(const int n);

// Draws a line and adds a label
void labelLine(const int n, const char* label);

// Draws a line
void line(const int n);

}
#endif
