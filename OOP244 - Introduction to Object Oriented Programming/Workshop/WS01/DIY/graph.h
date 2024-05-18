//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 19 Jan 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H

#include "io.h"
namespace seneca{

const int GRAPH_WIDTH = 79;

// finds the largest Mark Group in the Gp array, if it is larger than GRAPH_WIDTH,
// otherwise it will return GRAPH_WIDTH.
int findMax(const int *Gp);

// Prints a hidden line with n length
void printHiddenLine(const int n) ;

// prints a scaled bar relevant to the maximum value in samples array
void printBar(const int val,const int max);

// print the number label according to the group number (0-9)
void printNumLabel (const int n);

// Prints a graph comparing the sample values visually
void printGraph(const int * Gp, const int max);

}
#endif
