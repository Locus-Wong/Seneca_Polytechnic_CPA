//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 10 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// OOP244 Workshop #4 p1
//
// File    Fridge.cpp
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
#include <cstring>
#include <iostream>
#include "Fridge.h"
using namespace std;

namespace seneca{

   const char* Food::name() const {
      return m_name;
   }
   int Food::weight() const {
      return m_weight;
   }
   Food::Food() {}

   Food::Food(const char* nm, int wei) {
      strncpy(m_name, nm, NAME_LEN);
      m_weight = wei;
   }

    Fridge::Fridge(){
        m_numFoods = 0;
        m_model = nullptr;
    }
  
    Fridge::Fridge(Food farr[], int nf, const char* mod): m_numFoods(0), m_model(nullptr){
    
        
        if (nf > 0 && mod != nullptr && mod[0] != '\0'){
            m_numFoods = (nf > FRIDGE_CAP) ? FRIDGE_CAP : nf;
            m_model = new char[strlen(mod) + 1];
            strcpy(m_model, mod);
            for (int i = 0; i < m_numFoods; i++)
            {
                m_foods[i] = Food(farr[i].name(), farr[i].weight());  // use the constructor to assign value
            }
        
        }
    }

    Fridge::~Fridge(){
        delete[] m_model;
        m_model = nullptr;
    }

    bool Fridge::addFood(const Food& f){
        
        if (m_numFoods < FRIDGE_CAP)
        {
            m_foods[m_numFoods] = Food(f.name(), f.weight()); // use the constructor to assign value
            m_numFoods++;
            return true;
        }
        
        return false;
    }
    void Fridge::changeModel(const char* m){
        if (m != nullptr && m[0] != '\0')
        {
            delete[] m_model;
            m_model = new char[strlen(m) + 1];
            strcpy(m_model, m);
            
        }
        
       
    }
    bool Fridge::fullFridge() const{
        return m_numFoods == FRIDGE_CAP;
    }
    bool Fridge::findFood(const char* f) const{
        for (int i = 0; i < m_numFoods; i++)
        {
            if (strcmp(this->m_foods[i].name(), f) == 0)
            {
                return true;
            }
        }
        return false;
    }

    std::ostream& Fridge::display(std::ostream& os) const{
        
        if(m_model)
        {
            if (m_numFoods > 0)
            {
                os << "Fridge Model: " << m_model << endl;
                os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << endl;
                os << "List of Foods" << endl;
                for (int i = 0; i < m_numFoods; i++)
                {
                    os.width(20);
                    os << m_foods[i].name() << " | " << m_foods[i].weight() << endl;
                }
            }
            
        }
         
        return os;
    }
}
