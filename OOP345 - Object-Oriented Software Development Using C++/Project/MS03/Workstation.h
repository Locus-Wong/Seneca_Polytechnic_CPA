/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 03 Aug 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H
#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "Station.h"
namespace seneca
{
extern std::deque<CustomerOrder> g_pending; // holds the orders to be placed onto the assembly line at the first station.
extern std::deque<CustomerOrder> g_completed; // holds the orders that have been removed from the last station and have been completely filled.
extern std::deque<CustomerOrder> g_incomplete; // holds the orders that have been removed from the last station and could not be filled completely.

class Workstation : public Station // Each Workstation is-a-kind-of Station
{
    std::deque<CustomerOrder> m_orders; // Orders that have been placed on this station to receive service
    Workstation* m_pNextStation{};
    
public:
    Workstation(const std::string& name);
    
    // Deleting copy and move operations
    Workstation(const Workstation&) = delete;
    Workstation& operator=(const Workstation&) = delete;
    Workstation(Workstation&&) = delete;
    Workstation& operator=(Workstation&&) = delete;
    
    void fill(std::ostream& os);
    bool attemptToMoveOrder();
    void setNextStation(Workstation* station = nullptr);
    Workstation* getNextStation() const;
    void display(std::ostream& os) const;
    Workstation& operator+=(CustomerOrder&& newOrder);
};
}

#endif
