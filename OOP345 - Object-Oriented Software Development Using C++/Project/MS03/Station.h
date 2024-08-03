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
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <string>
namespace seneca
{
class Station {
    unsigned int m_stationId{};
    std::string m_itemName{};
    std::string m_stationDesc{};
    size_t m_serialNumber{};
    size_t m_qty{};
    static size_t m_widthField;
    static unsigned int id_generator;
    
public:
    Station(const std::string& record);
    const std::string& getItemName() const;
    size_t getNextSerialNumber();
    size_t getQuantity() const;
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
};
}
#endif
