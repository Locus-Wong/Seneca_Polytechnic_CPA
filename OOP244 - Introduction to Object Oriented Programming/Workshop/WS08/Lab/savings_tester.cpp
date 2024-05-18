/***********************************************************************
 // Workshop # 8, Virtual Functions and Abstract Base Classes
 //
 // File: savings_tester.cpp
 // Version 2.0
 // Date:
 // Author: Chris Szalwinski, Heidar Davoudi, Fardad Soleimanloo
 // Description
 // This file tests the SavingsAccount class
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 ***********************************************************************/
#include <iostream>
#include <cstring>
#include "iAccount.h"
#include "SavingsAccount.h"

using namespace seneca;
using namespace std;

// display inserts account information for client
//
ostream& line(size_t length) {
    cout.fill('*');
    cout.width(length);
    cout << "*" << endl;
    cout.fill(' ');
    return cout;
}
void display(const char* client, iAccount* const acct[], int n) {
    size_t lineLength = strlen(client) + 22;
    line(lineLength);
    cout << "DISPLAY Accounts for " << client << ":" << endl;
    line(lineLength);
    for (int i = 0; i < n; ++i) {
        acct[i]->display(cout);
        if (i < n - 1) cout << "-----------------------" << endl;
    }
    line(lineLength)<< endl;
}

// close a client's accounts
//
void close(iAccount* acct[], int n) {
    for (int i = 0; i < n; ++i) {
        delete acct[i];
        acct[i] = nullptr;
    }
}

int main() {
    // Create Accounts for Angelina
    iAccount* Angelina[2];
    
    // initialize Angelina's Accounts
    // (in the main program this will be done using the allocator module)
    Angelina[0] = new SavingsAccount(400.0,0.05);
    Angelina[1] = new SavingsAccount(400.0, 0.05);
    display("Angelina", Angelina, 2);
    
    cout << "DEPOSIT $2000 into Angelina's Accounts ..." << endl;
    for (int i = 0; i < 2; i++)
        Angelina[i]->credit(2000);
    
    cout << "WITHDRAW $1000 and $500 from Angelina's Accounts ... " << endl;
    Angelina[0]->debit(1000);
    Angelina[1]->debit(500);
    cout << endl;
    display("Angelina", Angelina, 2);
    
    Angelina[0]->monthEnd();
    Angelina[1]->monthEnd();
    display("Angelina", Angelina, 2);
    
    close(Angelina, 2);
    return 0;
}
