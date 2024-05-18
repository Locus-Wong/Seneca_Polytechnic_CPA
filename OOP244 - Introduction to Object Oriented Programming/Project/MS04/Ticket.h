#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace seneca
{
    class Ticket :public IOAble
    {
        Time m_time; //The time the Ticket was issued
        int m_number; //The ticket number; A sequential integer, starting from one and unique for each lineup.
    public:
        Ticket(int number);
        Time time()const;
        int number()const;
        void resetTime();
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
}
#endif // !SENECA_TICKET_H_