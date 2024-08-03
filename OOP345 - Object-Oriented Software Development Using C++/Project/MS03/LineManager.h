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
#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H
#include "Workstation.h"
#include <vector>
namespace seneca {
class LineManager {
    std::vector<Workstation*> m_activeLine; // the collection of workstations for the current assembly line
    size_t m_cntCustomerOrder{};// the total number of CustomerOrder objects
    Workstation* m_firstStation{}; // points to the first active station on the current line
    
public:
    LineManager(const std::string& file, const std::vector<Workstation*>& stations);
    void reorderStations();
    bool run(std::ostream& os);
    void display(std::ostream& os) const;
};
}

#endif
