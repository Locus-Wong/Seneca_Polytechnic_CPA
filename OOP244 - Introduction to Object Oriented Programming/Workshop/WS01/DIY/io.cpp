//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 19 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "io.h"

using namespace std;

namespace seneca{

// fill the remaining space with spaces to match the specified field width
    void printInt(const int value, const int fieldWidth) {
        cout << value;
        for (int i = 0; i < fieldWidth - intDigits(value); i++) {
            cout << " ";
        }
    }

// calculates the number of digits in the integer
    int intDigits(int value) {
        int count = (value == 0);
        while (value != 0) {
            value /= 10;
            ++count;
        }
        return count;
    }

    // moves the cursor backwards
    void goBack(const int n) {
        for (int i = 0; i < n; i++)
        {
            cout << "\b";
        }
    }

    // draw line
    void labelLine(const int n, const char* label) {
        cout << "+";
        for (int i = 0; i < n - 2; i++)
        {
            cout << "-";
        }
        cout << "+";
        if (label) {
            goBack(n - 4);
            cout << label;
        }
        cout << endl;
    }

    // print the +-----+ line with n length
    void line(const int n) {
        cout << "+";
        for (int i = 0; i < n - 2;  i++)
        {
            cout << "-";
        }
        cout << "+";
        cout << endl;
    }
}
