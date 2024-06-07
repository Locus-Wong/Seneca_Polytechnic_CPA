/*
 Name: Tsz Wa Wong
 Email: twwong9@myseneca.ca
 Student ID: 152181228
 Date: 6 June 2024
 I declare that this submission is the result of my own work and
 I only copied the code that my professor provided to complete my
 workshops and assignments. This submitted piece of work has not
 been shared with any other student or 3rd party content provider.
 */
#include <iostream>
#include <iomanip>
#include "Reservation.h"
namespace seneca{

std::string trim(const std::string& str){
    // Find the position of the first non-space character
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        start++;
    }
    // If the string is all spaces, return an empty string
    if (start == str.end()) {
        return "";
    }
    // Find the position of the last non-space character
    auto end = str.end();
    do {
        end--;
    } while (end > start && std::isspace(*end));
    // Return the trimmed string
    return std::string(start, end + 1);
}

void Reservation::update(int day, int time){
    m_day = day;
    m_hour = time;
}

Reservation::Reservation(const std::string& res){
    // Find positions of delimiters
    size_t pos1 = 0;
    size_t pos2 = res.find(':');
    size_t pos3 = res.find(',');
    size_t cnt = 0;
    while (pos3 != std::string::npos) {
        if(cnt == 0){
            // use pos1 and pos2 only for ID
            m_reservationID = trim(res.substr(pos1, pos2 - pos1));
            pos1 = pos2 + 1;
        }else if (cnt == 1){
            // use pos1 and pos3 only for name
            m_reservationName = trim(res.substr(pos1, pos3 - pos1));
            pos1 = pos3 + 1;
        }else if (cnt == 2){
            // use pos1 and pos3 only for email
            m_email = trim(res.substr(pos1, pos3 - pos1));
            pos1 = pos3 + 1;
        }else if (cnt == 3){
            // use pos1 and pos3 only for number of people
            std::string temp_numOfPeople = res.substr(pos1, pos3 - pos1);
            m_numOfPeople =std::stoi(temp_numOfPeople);
            pos1 = pos3 + 1;
        }else if (cnt == 4){
            // use pos1 and pos3 only for day
            std::string temp_day = res.substr(pos1, pos3 - pos1);
            m_day = std::stoi(temp_day);
            pos1 = pos3 + 1;
            
            // use pos1 and pos3 only for hour
            std::string temp_hour = res.substr(pos1);
            m_hour = std::stoi(temp_hour);
            pos1 = pos3 + 1;
        }
        // Find the next ','
        pos3 = res.find(',', pos1);
        cnt++;
    }
}

std::ostream& operator<<(std::ostream& os, const Reservation& res) {
    if (res.m_hour >= 6 && res.m_hour <= 9){
        os << "Reservation " << std::right << std::setw(10) << res.m_reservationID << ": "
        << std::right << std::setw(20) << res.m_reservationName << "  "
        << std::left << std::setw(20) << ("<" + res.m_email + ">") << "    "
        << "Breakfast on day " << res.m_day <<" @ "<< res.m_hour << ":00 for " << res.m_numOfPeople << (res.m_numOfPeople == 1 ? " person." : " people.") ;
        
    }else if (res.m_hour >= 11 && res.m_hour <= 15){
        os << "Reservation " << std::right << std::setw(10) << res.m_reservationID << ": "
        << std::right << std::setw(20) << res.m_reservationName << "  "
        << std::left << std::setw(20) << ("<" + res.m_email + ">") << "    "
        << "Lunch on day " << res.m_day <<" @ "<< res.m_hour << ":00 for " << res.m_numOfPeople << (res.m_numOfPeople == 1 ? " person." : " people.") ;
        
    }else if (res.m_hour >= 17 && res.m_hour <= 21){
        os << "Reservation " << std::right << std::setw(10) << res.m_reservationID << ": "
        << std::right << std::setw(20) << res.m_reservationName << "  "
        << std::left << std::setw(20) << ("<" + res.m_email + ">") << "    "
        << "Dinner on day " << res.m_day <<" @ "<< res.m_hour << ":00 for " << res.m_numOfPeople << (res.m_numOfPeople == 1 ? " person." : " people.") ;
        
    }else{
        os << "Reservation " << std::right << std::setw(10) << res.m_reservationID << ": "
        << std::right << std::setw(20) << res.m_reservationName << "  "
        << std::left << std::setw(20) << ("<" + res.m_email + ">") << "    "
        << "Drinks on day " << res.m_day <<" @ "<< res.m_hour << ":00 for " << res.m_numOfPeople << (res.m_numOfPeople == 1 ? " person." : " people.") ;
    }
    os << std::endl;
    return os;
}
}
