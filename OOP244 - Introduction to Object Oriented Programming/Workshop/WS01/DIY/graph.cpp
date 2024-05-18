//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 19 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "graph.h"

using namespace std;

namespace seneca {

    // finds the largest Mark Group in the Gp array, if it is larger than GRAPH_WIDTH,
    // otherwise it will return GRAPH_WIDTH.
    int findMax(const int *Gp)
    {
        int max = Gp[0]; // Set the max to the value of first index
        for (int i = 1; i < 10; i++)
        {
            if (max < Gp[i])  // Compare the values
            {
                max = Gp[i];   // Set max to the larger value if max is smaller
            }
        }
        return max <(GRAPH_WIDTH) ? GRAPH_WIDTH : max ;
    }

    // Prints a hidden line with n length
    void printHiddenLine(const int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "-";
        }
        cout << endl;
        
    }

    // prints a scaled bar relevant to the maximum value in samples array
    void printBar(const int val, const int max)
    {
        int barlength = 0;
        
        //calculate how many of * should be printed for the scaled sample values
        if (max == GRAPH_WIDTH)
        {
            barlength = val;
        }
        else
        {
            barlength = val * 65 / max;
        }
       cout << "| ";
       
        for (int i = 0; i < barlength; i++)
       {
          cout << "*";
       }
       
       cout << " ";
       printInt(val, (GRAPH_WIDTH - 8 - barlength)); // number label (4) + : "| "(2) + " "(1) + "|"(1) is equal to 8
       cout << "|" << endl;
    }

    void printNumLabel (const int n)
    {
        // print the number label according to the group number (0-9)
            if (n == 0)
            {
                printInt(100, 4);
            }
            else if (n == 1)
            {
                printInt(90, 4);
            }
            else if (n == 2)
            {
                printInt(80, 4);
            }
            else if (n == 3)
            {
                printInt(70, 4);
            }
            else if (n == 4)
            {
                printInt(60, 4);
            }
            else if (n == 5)
            {
                printInt(50, 4);
            }
            else if (n == 6)
            {
                printInt(40, 4);
            }
            else if (n == 7)
            {
                printInt(30, 4);
            }
            else if (n == 8)
            {
                printInt(20, 4);
            }
            else if (n == 9)
            {
                printInt(10, 4);
            }
    }

    // prints a graph comparing the sample values visually
    void printGraph(const int * Gp, const int max)
    {
            // As we know there are 10 groups of mark range, we loop 10 times
            for (int i = 0; i < 10; i++)
            {
                printNumLabel(i);
                printBar(Gp[i], max);
            }
        }

    }
