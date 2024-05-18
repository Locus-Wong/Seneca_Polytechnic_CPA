//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 10 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// OOP244 Workshop #4 p2
//
// File    Fridge.h
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <cstring>
#include <iostream>
#define FRIDGE_CAP 3

namespace seneca{

   const int NAME_LEN = 20;

   class Food {
       char m_name[NAME_LEN]{};
      int m_weight{};
   public:
      const char* name()const;
      int weight()const;
      Food();
      Food(const char* nm, int wei);
   };

    class Fridge {
        Food m_foods[FRIDGE_CAP]; // A statically allocated array of Food items whose size is defined by the FRIDGE_CAP constant
        int m_numFoods; // The number of Food items currently stored by the Fridge
        char* m_model; // dynamic c-style string that represents the model name of the Fridge
        
    public:
        Fridge();
        ~Fridge();
        Fridge(Food farr[], int nf, const char* mod = "Ice Age");
        bool addFood(const Food& f);
        void changeModel(const char* m);
        bool fullFridge() const;
        bool findFood(const char* f) const;
        std::ostream& display(std::ostream& os = std::cout) const;
        
    };


}

#endif
