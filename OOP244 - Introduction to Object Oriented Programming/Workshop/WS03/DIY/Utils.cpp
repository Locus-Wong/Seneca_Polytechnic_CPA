//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 7 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Some parts of the code in Utils are references to my professor's.
#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca
{
    Utils ut;
    int Utils::getInt(int max, int min)
    {
        int val{};
        cin >> val;
        while (cin.fail() || val < min || val > max)
        {
            if (!cin.fail())
            {
                cout << "Invlid value(1<=val<=" << max << ")\n> ";
            }
            else
            {
                cout << "Invalid entry, retry\n> ";
            }
            cin.clear();
            cin.ignore(12000, '\n');
            cin >> val;      
        }
        cin.ignore(12000, '\n'); // clear the input buffer again to prevent later buffer
        return val;
    }

    bool Utils::getLine()
    {
        string val;
        getline(cin, val);

            while (cin.fail() || (val != "Y" && val != "y" && val != "N" && val != "n"))
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(12000, '\n');
                }
                cout << "Only Y or N are acceptable:\n> ";
                getline(cin, val);
            }
        
        return (val == "y" || val == "Y");
                   
    }
}
