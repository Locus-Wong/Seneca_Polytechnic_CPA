//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 14 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_



namespace seneca
{
    const int ACCT_MAXLEN_USER = 16; // Max Length of user name
    

   // Class Definition
   class bankAccount
   {

       private:
          // Data Members
           char    m_userName[ACCT_MAXLEN_USER];
           double    m_funds;
           bool    m_checking;
           int        m_monthlyTransactions;
            //You are free to create additional private data members which may be helpful.
           bool isOpen() const;
      
        public:
           const double CHECK_TRAN_FEE = 1.25;
           const double SAV_TRAN_FEE = 3.50;
           const double CHECK_INT_RATE = 0.5;
           const double SAV_INT_RATE = 2.5;
           bankAccount(const char* name = nullptr, bool checking = false);
           bool setup(const char* name, bool checking);

           // Type Conversion OR Cast Operator
           operator bool() const;
           operator double() const;
           // Unary Operators
           bankAccount& operator++(); // pre-fix operators
           bankAccount& operator--(); // pre-fix operators
           // Binary Operators
           bool operator+= (double deposit);
           bool operator-= (double withdrawl);
           bool operator== (const bankAccount& otherBankAccount) const;
           bool operator> (double amount) const;
           bool operator<= (double amount) const;
           
           // Additional Methods
           bool operator<<(bankAccount& otherBankAccount);
           void display (void) const;
       
   };

        // Global Helper Functions (non-member helper functions/operators)
        bool operator> (double lhs, const bankAccount& rhs);
        bool operator<= (double lhs, const bankAccount& rhs);
}
#endif
