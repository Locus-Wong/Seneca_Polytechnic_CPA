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
#include <deque>
#include <string>
#include <iostream>
#include "Workstation.h"

namespace seneca {
std::deque<CustomerOrder> g_pending;
std::deque<CustomerOrder> g_completed;
std::deque<CustomerOrder> g_incomplete;

Workstation::Workstation(const std::string& name) : Station(name) {};

void Workstation::fill(std::ostream& os)
{
    if (!m_orders.empty()) // thera are orders to fill
    {
        m_orders.front().fillItem(*this, os); // call CustomerOrder::fillItem passing the current object and the ostream object
    }
}

bool Workstation::attemptToMoveOrder()
{
    if (!m_orders.empty()) // if there are orders in the queue
    {
        CustomerOrder& frontOrder = m_orders.front(); // get the front order
        
        if (frontOrder.isItemFilled(this->getItemName()) || this->getQuantity() <= 0)  // if all the iterms with the same name in the order are filled or the itemName doesn't exist in the order or the inventory of current station is empty, return true
        {
            
            if (m_pNextStation) // if there is a next station
            {
                *m_pNextStation += std::move(frontOrder); // use the overloaded operator+= to move the order to the next station
            }
            else // if the order cannot be filled
            {
                if (frontOrder.isOrderFilled()) // if the order is filled
                {
                    g_completed.push_back(std::move(frontOrder));
                }
                else
                {
                    g_incomplete.push_back(std::move(frontOrder));
                }
            }
            
            m_orders.pop_front();
            return true;
        }
    }
    return false;
}

void Workstation::setNextStation(Workstation* station)
{
    m_pNextStation = station;
}

Workstation* Workstation::getNextStation() const
{
    return m_pNextStation;
}

void Workstation::display(std::ostream& os) const
{
    os << this->getItemName() << " --> ";
    if (m_pNextStation)
    {
        os << m_pNextStation->getItemName();
    }
    else
    {
        os << "End of Line";
    }
    os << '\n';
}

Workstation& Workstation:: operator+=(CustomerOrder&& newOrder)
{
    m_orders.push_back(std::move(newOrder)); // moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
    return *this;
}

}




