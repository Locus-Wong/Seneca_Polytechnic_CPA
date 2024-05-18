//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 13 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca{
   const char* GuitarStr::material() const {
      return m_material;
   }
   double GuitarStr::gauge() const {
      return m_gauge;
   }
   GuitarStr::GuitarStr() {};

   GuitarStr::GuitarStr(const char* ma, double ga) {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };


    Guitar::Guitar(){
        strncpy (m_model, "Stratocaster", MOD_LEN); // default value : "Stratocaster"
    };

    Guitar::Guitar(const char* mod){
        
        if(mod)
        {
            strncpy (m_model, mod, MOD_LEN);
        }
    };

    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod){
        
        if (strs[0].material() && strs[0].gauge() && ns != 0 && mod)
        {
            m_strings = new GuitarStr[ns];
            for (int i = 0; i < ns; i++){
                m_strings[i] = GuitarStr(strs[i].material(), strs[i].gauge());
                // use strs[i].material() , strs[i].gauge() to get the value of private member
                // use the constructor GuitarStr(const char* ma, double ga) to initialize each GuitarStr Object
            }
            m_numStrings = ns;
            strncpy (m_model, mod, MOD_LEN);
        }
        else
        {
            *this = Guitar(); // creating a temporary Guitar object using the default constructor and then assigning it to the current object.
        }
        
        
    };

    Guitar::~Guitar(){
        delete[] m_strings;
        m_strings = nullptr;
        m_numStrings = 0;
        m_model[0] = '\0';
    };

    bool Guitar::changeString(const GuitarStr& gs, int sn){
        if(sn < 0 || sn > m_numStrings - 1){
            return false;
        }
        
            m_strings[sn] = gs;
            return true;
        
    };

    void Guitar::reString(GuitarStr strs[], int ns){
        delete[] m_strings;
        m_strings = new GuitarStr[ns];
        for (int i = 0; i < ns; i++) {
                m_strings[i] = strs[i];
            }
        m_numStrings = ns;
        
    };

    void Guitar::deString(){
                delete[] m_strings;
              m_strings = nullptr;
                m_numStrings = 0;
        }
    

    bool Guitar::strung() const{
        if(m_strings){
            return m_strings[0].material() && m_strings[0].gauge();
        }
        return false;
    };

    bool Guitar::matchGauge(double ga) const{
        if (m_strings){
            for (int i = 0; i < m_numStrings; i++)
            {
                if(m_strings[i].gauge() == ga)
                {
                    return true;
                }
            }
        }
        return false;
    };

    std::ostream& Guitar::display(std::ostream& os) const{
        if (m_numStrings && m_strings && m_model[0] != '\0'){
            os << "Guitar Model: " << m_model << endl;
            os << "Strings: " << m_numStrings << endl;
        }
        else{
            os << "***Empty Guitar***" << endl;
        }
        os.precision(1);
        if (this->strung()){
            for (int i = 0; i < m_numStrings; i++){
                os << "#" << i + 1;
                os.width(MAT_LEN);
                os << m_strings[i].material();
                os << " | ";
                os << m_strings[i].gauge();
                os << endl;
            }
        }
        
        
        return os;
    };

};
