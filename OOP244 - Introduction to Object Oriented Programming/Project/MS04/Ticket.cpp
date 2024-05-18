#include <iostream>
#include "Ticket.h"
using namespace std;
namespace seneca
{
    Ticket::Ticket(int number)
    {
        m_number = number; //Constructs a Ticket by setting the m_number member variable
    }
    Time Ticket::time() const
    {
        return m_time; //A query that returns the time when the ticket was issued
    }
    int Ticket::number() const
    {
        return m_number; //A query that returns the ticket number
    }
    void Ticket::resetTime()
    {
        m_time.reset(); //calls Time& Time::reset() which resets the Time object to the current time by using the U.getTime() method
    }
    std::ostream& Ticket::write(std::ostream& ostr) const
    {
        if (&ostr != &cout)
        {
            ostr << m_number << "," << m_time; //Inserts comma-separated ticket number and time into ostream 
        }
        else
        {
            ostr << "Ticket No: " << m_number << ", Issued at: " << m_time; //Inserts ticket number and time into ostream
        }
        return  ostr;
    }
    std::istream& Ticket::read(std::istream& istr)
    {
        istr >> m_number;
        istr.ignore(); //discards one character from the input stream
        return istr >> m_time;
    }
}