//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 14 Feb 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> // for abs

using namespace std;

namespace seneca
{
    // Default Constructor with default arguments
    bankAccount::bankAccount(const char* name, bool checking)
    {
        m_userName[0] = '\0';        // Empty string implies is account is not open
        setup(name, checking);
    }

    // Open bank account: setup can only be done once!
    bool bankAccount::setup(const char* name, bool checking)
    {
        if (isOpen())
            return false;
        if (name == nullptr)
            return false;

        strcpy(m_userName, name);
        m_monthlyTransactions = 0;
        m_checking = checking;
        m_funds = 0;
        return true;
    }

    // Account is open if user name string is not empty
    bool bankAccount::isOpen() const
    {
        return (m_userName[0] != '\0');
    }

    // Type Conversion OR Cast Operators
    bankAccount::operator bool() const{ // Conversion operator that converts an object of the bankAccount class to a boolean value.
        return isOpen();
    }
    bankAccount::operator double() const{ // Conversion operator that converts an object of the bankAccount class to a double value.
        return m_funds;
    }

    // Unary Operators
    bankAccount& bankAccount::operator++(){
        if (*this && m_funds > 0){ //check if the account has been opened and have funds
            if(m_checking){
                m_funds += m_funds * CHECK_INT_RATE / 100; // Checking account interest
            }
            else{
                m_funds += m_funds * SAV_INT_RATE / 100; // Saving account interest
            }
        }
        return *this; // Returns reference to the current object
    }

    bankAccount& bankAccount::operator--(){
        if (*this){ //check if the account has been opened
            if(m_checking){ // Checking account transaction fee
                m_funds -= m_monthlyTransactions * CHECK_TRAN_FEE;
            }
            else{   // Saving account transaction fee
                m_funds -= m_monthlyTransactions * SAV_TRAN_FEE;
            }
        }
        return *this; //Returns reference to the current object
    }


    // Binary Operators
    bool bankAccount::operator+= (double deposit){
        if (*this){ //check if the account has been opened
            m_funds += deposit;
            m_monthlyTransactions++; // increments the number of transactions
            if (deposit >= 0){
                cout.setf(ios::fixed);
                cout.precision(2);
                cout <<"Deposit $" << deposit << " for " << m_userName << endl;
            }else{
                cout <<"Withdraw $" << abs(deposit) << " for " << m_userName << endl;
            }
            return true;
        }
        return false;
    }

    bool bankAccount::operator-= (double withdrawl){
        if(*this){
            return operator+=(-withdrawl); //multiplying the specified value by -1 and invoking operator+= above
        }
        return false;
    }

    bool bankAccount::operator== (const bankAccount& otherBankAccount) const{

     if(!strcmp(otherBankAccount.m_userName, m_userName) && abs(otherBankAccount.m_funds - m_funds) < 0.001 && otherBankAccount.m_checking == m_checking) // checks if the specified bank account has the same user name, funds and type as this
     {
         return true;
     }
     return false;
     
    }

    bool bankAccount::operator> (double amount) const{
        if(*this){ //check if the account has been opened
            if(m_funds > amount){
                return true;
            }
        }
        
     return false;
    }

    bool bankAccount::operator<= (double amount) const{
        if(*this){
                return !(operator> (amount)); // invoking operator> from above and reversing the result
            }
     return false;
    }

    // Additional Methods
     bool bankAccount::operator<<(bankAccount& otherBankAccount){
         if(*this && otherBankAccount){ // check if both this account and the source account are open
             if(otherBankAccount.m_funds > 0){
                 cout.precision(2);
                 cout << "Transfer $" << otherBankAccount.m_funds << " from "<< otherBankAccount.m_userName << " to " << m_userName << endl;
                 *this += otherBankAccount.m_funds; // Deposit all the funds from the specified account
                 otherBankAccount -= otherBankAccount.m_funds; // Withdrawl all the funds from the otherBankAccount
                 return true;
             }
             
         }
         return false;
     }

     void bankAccount::display (void) const{
         if(*this){
             cout.precision(2);
             cout.setf(ios::fixed);
             cout << "Display Account -> User:";
             cout.fill('-');
             cout.width(16); // total width for -----username
             cout << m_userName << " | ";
             cout.fill(' '); // set back to default
             cout.width(8);
             cout << (m_checking? "Checking" : "Savings") <<" | Balance: $  ";
             cout.width(6); // width for funds
             cout << m_funds <<" | Transactions:";
             cout.fill('0');
             cout.width(3); // width for monthly transactions
             cout << m_monthlyTransactions << endl;
             cout.fill(' '); // set back to default
             
         }else{
             cout << "Display Account -> User:------- NOT OPEN" << endl;
         }
     }

    // Global Helper Functions (non-member helper functions/operators)
    bool operator> (double lhs, const bankAccount& rhs){
     if(rhs){ // Use the (bool) cast operator to confirm the rhs account is open
         return lhs > (double) rhs; // use (double) cast operator to get the funds from the rhs account
     }
     return false;
    }

    bool operator<= (double lhs, const bankAccount& rhs){
     if(rhs){ // Use the (bool) cast operator to confirm the rhs account is open
         return !(lhs > rhs); //invoking the above global helper operator> and reversing the result
     }
     return false;
    }
}
